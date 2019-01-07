#include "kmint/pigisland/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"

namespace kmint {
namespace pigisland {
	shark::shark(kmint::map::map_graph &g, play::stage &stage)
		: play::map_bound_actor{ g, find_shark_resting_place(g) },
		drawable_{ *this, shark_image() }, map_{ &g }, resting_place_(&node()), _stage(stage)
	{
		_actorType = play::ActorType::Shark;
	}


		void shark::act(delta_time dt) {
			t_since_move_ += dt;

  for(auto &itr = begin_perceived(); itr != end_perceived(); ++itr)
  {
	  if(itr->incorporeal())
	  {
		  if(math::distance(location(), itr->location()) < 16)
		  {
			  itr->kill();
		  }

		  itr->FleeLocation(&location());
	  }

			}


			//If mag bewegen
			if (to_seconds(t_since_move_) >= waiting_time(node())) {

				std::vector<const map::map_node*> tempPath = AstarPath(graph(), &node(), destinationNode());
				auto nextNode = tempPath[1];
				if (nextNode != nullptr)
				{
					node(*nextNode);
				}
				else
				{
					node(random_adjacent_node(node()));
				}
				moveEnduranceEffect();

				t_since_move_ = from_seconds(0);
			}
		}

	} // namespace pigisland
} // namespace kmint
