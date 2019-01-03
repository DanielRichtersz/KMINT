#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/random.hpp"
#include <algorithm>
#include <map>

namespace kmint {
	namespace pigisland {

		map::map_node const &random_adjacent_node(map::map_node const &node) {
			int r = random_int(0, node.num_edges());
			return node[r].to();
		}

		map::map_node const &find_node_of_kind(map::map_graph const &graph, char kind) {
			auto i = std::find_if(graph.begin(), graph.end(), [kind](auto const &node) {
				return node.node_info().kind == kind;
			});
			return *i;
		}

		map::map_node const &find_random_mooring_place(map::map_graph const &graph) {
			return find_node_of_kind(graph, '1' + random_int(0, 3));
		}

		map::map_node const &find_shark_resting_place(map::map_graph const &graph) {
			return find_node_of_kind(graph, 'K');
		}

		int waiting_time(map::map_node const &node) {
			return static_cast<int>(node[0].weight());
		}

		std::vector<const map::map_node*> DijkstraShortestPath(map::map_graph const &graph, const map::map_node* startNode, const map::map_node* endRoom) {
			std::map<const map::map_node*, std::pair<const map::map_node*, float>> cost;
			std::vector<const map::map_node*> visited;
			std::vector<const map::map_node*> unvisited;
			std::vector<const map::map_node*> reversePath;

			const map::map_node* currentNode = startNode;

			//Add all rooms to unvisited list
			for (std::size_t i = 0; i < graph.num_nodes(); ++i) {
				if (&graph[i] != startNode) {
					unvisited.push_back(&graph[i]);
				}
			}

			//Remove startnode from unvisited
			auto& it = std::find_if(unvisited.begin(), unvisited.end(), [startNode](const map::map_node* n) { return math::distance(startNode->location(), n->location()) != 0; });

			if (it != unvisited.end()) {
				unvisited.erase(it);
			}

			//Add startroom to visited
			visited.push_back(startNode);

			//Add startroom to cost with a cost of 0
			cost[startNode] = std::pair{ nullptr, 0 };

			//While there are still unvisited rooms
			while (!unvisited.empty()) {
				//For each edge on current node 
				for (auto& edgeIt = currentNode->begin(); edgeIt != currentNode->end(); ++edgeIt) {

					//Set maxvalue to cost
					float currentCost = std::numeric_limits<float>::max();

					//Get connected room
					const map::map_node* connectedNode = &edgeIt->to();

					//Calculate cost
					currentCost = cost[currentNode].second + edgeIt->weight();

					//Compare costs
					//-Find node in cost map
					std::map<const map::map_node*, std::pair<const map::map_node*, float>>::iterator connectedNodeIt = cost.find(connectedNode);

					//-If node exists in cost map
					if (connectedNodeIt != cost.end())
					{
						//-If cost was higher than current cost, replace
						if (connectedNodeIt->second.second > currentCost) {
							connectedNodeIt->second = std::pair{ currentNode, currentCost };
						}
					}
					else {
						//-Else place new in cost map
						cost[connectedNode] = std::pair{ currentNode, currentCost };
					}
				}

				// Set lowestcost again to maxvalue to compare it with other values
				float lowestCost = std::numeric_limits<float>::max();

				//Foreach item pair in cost
				for (auto costPairIt = cost.begin(); costPairIt != cost.end(); ++costPairIt) {
					//If the value is lower than lowestCost and the room isn't in visited anymore, 
					//set currentRoom to x.key and lowestCost to the cost of x.key
					//x is a node
					auto &x = *costPairIt;

					//-If node doesnt exist in costmap
					if (std::find(visited.begin(), visited.end(), costPairIt->first) == visited.end()) {
						//And if currentcost is less than lowestcost
						if (x.second.second < lowestCost) {
							//Replace currentNode
							currentNode = x.first;
							lowestCost = x.second.second;
						}
					}
				}

				//Remove currentNode from unvisited
				auto& it = std::find_if(unvisited.begin(), unvisited.end(), [currentNode](const map::map_node* n) { return math::distance(currentNode->location(), n->location()) != 0; });

				if (it != unvisited.end()) {
					unvisited.erase(it);
				}

				//If currentNode == endNode, break
				if (math::distance(currentNode->location(), endRoom->location()) == 0) {
					break;
				}

				//Add currentNode to visited
				visited.push_back(currentNode);
			}

			const map::map_node* reverse = endRoom;
			while (reverse != nullptr) {

				//TODO: Draw route animation
				reversePath.push_back(reverse);
				reverse = cost[reverse].first;
			}

			std::reverse(reversePath.begin(), reversePath.end());
			return reversePath;
		}

		//void RemoveMapNodeFromVector(std::vector<const kmint::map::map_node*> vector, const kmint::map::map_node* mapNode)
		//{
		//	//Remove currentRoom from unvisited and add to visited
		//	std::vector<const map::map_node*>::iterator it = std::find(vector.begin(), vector.end(), *mapNode);
		//	if (it != vector.end()) {
		//		vector.erase(it);
		//	}
		//}


	} // namespace pigisland



	// namespace kmint
}