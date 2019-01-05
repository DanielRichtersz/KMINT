#include "kmint/pigisland/shark.hpp"
#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"

namespace kmint {
namespace pigisland {
	shark::shark(kmint::map::map_graph &g, play::stage &stage)
		: play::map_bound_actor{ g, find_shark_resting_place(g) },
		drawable_{ *this, shark_image() }, map_{ &g }, resting_place_(&node()), _stage(stage)
	{
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
	  const map::map_node* nextNode = nullptr;


	  num_colliding_actors();

	  if (destinationNode() == nullptr) {
		  destinationNode(find_random_mooring_place(graph()));
	  }

	  while (math::distance(destinationNode()->location(), node().location()) == 0) {
		  destinationNode(find_random_mooring_place(graph()));
	  }

	  if (destinationNode() != nullptr) {
		  std::vector<const map::map_node*> tempVector = DijkstraShortestPath(graph(), &node(), destinationNode());
		  nextNode = tempVector.at(1);
	  }

	  //If next node exists, move to that node
	  if (nextNode != nullptr) {
		  node(*nextNode);
	  }
	  else { //Move to random node, should never happen unless something goes really wrong
		  node(random_adjacent_node(node()));
	  }

	  if(steps > 100)
	  {

	  }

	  t_since_move_ = from_seconds(0);
  }
}

} // namespace pigisland
} // namespace kmint
