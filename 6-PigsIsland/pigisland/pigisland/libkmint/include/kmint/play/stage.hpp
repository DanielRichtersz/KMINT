#ifndef KMINT_PLAY_STAGE_HPP
#define KMINT_PLAY_STAGE_HPP

#include "../../pigisland/include/kmint/pigisland/node_algorithm.hpp"
#include "kmint/play/actor.hpp"
#include "kmint/primitives.hpp"
#include "kmint/util/deref_unique_ptr.hpp"
#include "kmint/util/wrapped_iterator.hpp"
#include <memory>
#include <type_traits>
#include <vector>
#include <map>
#include <iostream>

namespace kmint {
namespace pigisland
{
class FlockingPig;
class pig;
class algs;
}
namespace play {

class stage {
  using container = std::vector<std::unique_ptr<actor>>;

public:
  using iterator = kmint::util::wrapped_iterator<actor, container::iterator>;
  using const_iterator =
      kmint::util::wrapped_iterator<const actor, container::const_iterator>;
  stage() = default;
  ~stage() = default;
  stage(stage &&) = default;
  stage(stage const &) = delete;

  stage &operator=(stage const &) = delete;
  stage &operator=(stage &&) = default;

  void act(delta_time dt);

  /*!
    \brief Constructs an actor.

    This is the only way to create an actor that is to be used on stage. This
    member function accepts an arbitrary number of parameters that are forwarded
    to the actor's constructor.

    \tparam T The class of the actor. Must be the type of a concrete subclass of
    actor.
    \return A reference to the newly created actor. This reference is valid
    until either the actor is explicitly removed by a call to remove_actor or
    stage lifetime ends.
   */
  template <typename T, typename... Args>
  T &build_actor(Args &&... constructor_arguments) {
    static_assert(std::is_convertible<T *, actor *>::value,
                  "This function can only construct"
                  " concrete subclasses of actor");
    static_assert(std::is_constructible<T, Args...>::value,
                  "The requested type cannot be constructed from"
                  "the arguments provided.");
    actors_.push_back(
        std::make_unique<T>(std::forward<Args>(constructor_arguments)...));
    return *(static_cast<T *>(actors_.back().get()));
  }

  /*!
    \brief Removes an actor from play.

    This function removes the actor from the list of actors on stage. As the
    stage owns the actor, the actor will be removed from memory and the actor's
    destructor will be called. Any reference or pointer to that actor is now
    invalid.

    \param a Actor to remove from play.
   */
  void remove_actor(actor const &a);

  iterator begin();
  iterator end();
  const_iterator cbegin() const;
  const_iterator cend() const;
  const_iterator begin() const;
  const_iterator end() const;
  container *getActors() { return &actors_; }
  container *getToDelete() { return &toDelete; }

  void createNextGeneration() {
    std::map<int, kmint::play::actor *> pigsMap;
    std::vector<pigisland::FlockingPig> pigGenes;
    int i = 0;
    std::for_each(begin(), end(),
    [&i, &pigsMap, &pigGenes](play::actor &a) {
      kmint::play::actor *const newPig = &a;
      if (newPig->isFreeRoamingActor()) {
        if (!newPig->isKilled()) {
          pigGenes.emplace_back(newPig->getPig());
        }
        newPig->kill();
        pigsMap[i] = newPig;
        i++;
      }
    });

    for (int i = 0; i < 100; i++) {

      pigisland::FlockingPig PeppaPig;
      pigisland::FlockingPig parent1 =
          pigGenes[random_scalar(0, pigGenes.size() - 1)];
      pigisland::FlockingPig parent2 =
          pigGenes[random_scalar(0, pigGenes.size() - 1)];

      PeppaPig.setAlignment(random_scalar(parent1.getAlignment() - 0.1f,
                                          parent1.getAlignment() + 0.1f));
      PeppaPig.setAttractionToBoat(
          random_scalar(parent1.getAttracktionToBoat() - 0.1f,
                        parent1.getAttracktionToBoat() + 0.1f));
      PeppaPig.setAttractionToShark(
          random_scalar(parent1.getAttracktionToShark() - 0.1f,
                        parent1.getAttracktionToShark() + 0.1f));

      PeppaPig.setCohesion(random_scalar(parent2.getCohesion() - 0.1f,
                                         parent2.getCohesion() + 0.1f));
      PeppaPig.setSeperation(random_scalar(parent2.getSeperation() - 0.1f,
                                           parent2.getSeperation() + 0.1f));

      pigsMap[i]->setGenes(PeppaPig);
      pigsMap[i]->reset();
    } 
  }

private:
  std::vector<std::unique_ptr<actor>> actors_;
  container toDelete;
};
} // namespace play
} // namespace kmint
#endif
