#include "kmint/play/stage.hpp"
#include "../../../../pigisland/include/kmint/pigisland/boat.hpp"
#include "../../../../pigisland/include/kmint/pigisland/shark.hpp"
#include "kmint/play/actor.hpp"
#include <algorithm>

namespace kmint {
namespace play {

namespace {
template <typename ForwardIt>
void check_interactions(ForwardIt begin, ForwardIt end) {
  for (auto i = begin; i != end; ++i) {
    // ++ForwardIt{i} ensures that j points one element further than i
    // This reduces the constant factor of the algorithm by approximately 1/2.
    for (auto j = ++ForwardIt{i}; j != end; ++j) {
      if (i == j) {
        continue;
      }
      if (collision(*i, *j)) {
        i->register_collision(*j);
        j->register_collision(*i);
      }
      if (sees(*i, *j)) {
        i->register_perceived(*j);
      }
      if (sees(*j, *i)) {
        j->register_perceived(*i);
      }
    }
  }
}
} // namespace

void stage::act(delta_time dt) {
  // system("CLS");
  // std::cout << "---------------------------------------------------" <<
  // std::endl;
  check_interactions(begin(), end());

  for (actor &a : *this) {
    if (a.GetActorType() == ActorType::Shark) {
      pigisland::shark &sharkActor = dynamic_cast<pigisland::shark &>(a);

      if (&sharkActor != nullptr) {

        if (math::distance(sharkActor.location(),
                           sharkActor.getRestingPlace()->location()) == 0) {
          if (sharkActor.getEndurance() == 0) {

            std::cout << "Total pigs eaten: " << sharkActor.getPigsEaten()
                      << std::endl;
            createNextGeneration();
            sharkActor.increaseGenerations();
            sharkActor.resetPigsEaten();
            std::cout << "-----" << std::endl
                      << "Generation " << sharkActor.getGenerations()
                      << " created" << std::endl
                      << "-----" << std::endl;
          }
        }

        pigisland::SharkBaseState *sharkBaseState =
            _finiteStateMachine.SetSharkDestination(&sharkActor);
        if (sharkBaseState != nullptr) {
          sharkBaseState->Execute(&sharkActor);
        }
      }
    }

    if (a.GetActorType() == ActorType::Boat) {
      pigisland::boat &boatActor = dynamic_cast<pigisland::boat &>(a);
      if (&boatActor != nullptr) {
        pigisland::BoatBaseState *boatBaseState =
            _finiteStateMachine.SetBoatDestination(&boatActor);
        if (boatBaseState != nullptr) {
          boatBaseState->Execute(&boatActor);
        }
      }
    }
    a.act(dt);
  }

  std::for_each(begin(), end(), [](actor &a) {
    a.empty_collisions();
    a.empty_perceived();
  });
}

void stage::remove_actor(actor const &a) {
  actors_.erase(
      std::remove_if(actors_.begin(), actors_.end(),
                     [&a](auto const &ptr) { return &a == ptr.get(); }),
      actors_.end());
}
stage::iterator stage::begin() {
  return {actors_.begin(), util::deref_unique_ptr<actor>};
}
stage::iterator stage::end() {
  return {actors_.end(), util::deref_unique_ptr<actor>};
}
stage::const_iterator stage::cbegin() const {
  return {actors_.begin(), util::deref_unique_ptr_const<actor>};
}
stage::const_iterator stage::cend() const {
  return {actors_.end(), util::deref_unique_ptr_const<actor>};
}
stage::const_iterator stage::begin() const { return cbegin(); }
stage::const_iterator stage::end() const { return cend(); }

} // namespace play

} // namespace kmint
