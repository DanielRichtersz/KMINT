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
			for (auto &itr = begin_perceived(); itr != end_perceived(); ++itr)
			{

				if (itr->incorporeal())
				{
					auto loc = &location();
					itr->SeekLocation(loc);
				}

			}

			t_since_move_ += dt;
			if (to_seconds(t_since_move_) >= waiting_time(node())) {
				//node(random_adjacent_node(node()));
				const map::map_node* nextNode = nullptr;

				if (destinationNode() == nullptr) {
					destinationNode(find_random_mooring_place(graph()));
				}

				while (math::distance(destinationNode()->location(), node().location()) == 0) {
					destinationNode(find_random_mooring_place(graph()));
				}
				
				if (destinationNode() != nullptr) {
					auto dest = destinationNode();
					std::vector<const map::map_node*> tempVector = AstarPath(graph(), &node(), dest);
					nextNode = tempVector.at(1);
				}

				//If next node exists, move to that node
				if (nextNode != nullptr) {
					node(*nextNode);
				}
				else { //Move to random node, should never happen unless something goes really wrong
					node(random_adjacent_node(node()));
				}

				t_since_move_ = from_seconds(0);
			}
		}



	} // namespace pigisland
} // namespace kmint
