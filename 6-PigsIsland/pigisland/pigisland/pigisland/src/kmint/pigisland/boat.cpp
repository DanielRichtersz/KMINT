#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include <iostream>

namespace kmint {
	namespace pigisland {

		boat::boat(kmint::map::map_graph &g)
			: play::map_bound_actor{ g, find_random_mooring_place(g) },
			drawable_{ *this, boat_image() } /*, map_{&g}*/
		{
			_actorType = play::ActorType::Boat;
		}

		void boat::act(delta_time dt) {

			// Pass to pigs the location of boat
			for (auto &itr = begin_perceived(); itr != end_perceived(); ++itr)
			{

				if (itr->incorporeal())
				{
					if (math::distance(location(), itr->location()) < 16)
					{
						itr->kill();
					}
					auto loc = &location();
					itr->SeekLocation(loc);
				}

			}

			t_since_move_ += dt;

			// FSM
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
