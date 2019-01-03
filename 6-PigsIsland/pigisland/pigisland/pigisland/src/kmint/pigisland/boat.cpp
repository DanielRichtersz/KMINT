#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"

namespace kmint {
	namespace pigisland {

		boat::boat(kmint::map::map_graph &g)
			: play::map_bound_actor{ g, find_random_mooring_place(g) },
			drawable_{ *this, boat_image() } /*, map_{&g}*/ {}

		void boat::act(delta_time dt) {
			t_since_move_ += dt;
			if (to_seconds(t_since_move_) >= waiting_time(node())) {
				//node(random_adjacent_node(node()));
				const map::map_node* nextNode = nullptr;
				destinationNode(find_random_mooring_place(graph()));
				if (destinationNode() == nullptr || math::distance(destinationNode()->location(), node().location())) {
					nextNode = DijkstraShortestPath(graph(), &node(), destinationNode())[0];
				}

				if (nextNode != nullptr) {
					node(*nextNode);
				}
				else {
					node(random_adjacent_node(node()));
				}

				t_since_move_ = from_seconds(0);
			}
		}



	} // namespace pigisland
} // namespace kmint
