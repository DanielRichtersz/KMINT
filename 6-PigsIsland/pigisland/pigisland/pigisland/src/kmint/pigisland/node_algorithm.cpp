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
		
	} // namespace pigisland

	//std::vector<map::map_node> DijkstraShortestPath(map::map_graph const &graph, map::map_node& startNode, map::map_node& endRoom) {
	//	std::map<map::map_node, std::pair<map::map_node, int>> cost;
	//	std::vector<map::map_node> visited;
	//	std::vector<map::map_node> unvisited;
	//	std::vector<map::map_node> reversePath;

	//	auto &currentNode = startNode;


	//	for (auto it = graph.begin(); it != graph.end(); ++it) {
	//		auto &node = *it;
	//		if (node.location != startNode.location) {
	//			unvisited.push_back(&node);
	//		}
	//	}


	//	//Add startroom to visited
	//	visited.push_back(startNode);

	//	//Add startroom to cost with a cost of 0
	//	cost[startNode] = std::pair{ startNode, 0 };

	//	//While there are still unvisited rooms
	//	while (!unvisited.empty()) {
	//		//To show what rooms are visited by the algorithm
	//		currentNode.tagged(true);

	//		//For each edge on current node 
	//		for (auto edgeIt = currentNode.begin(); edgeIt != currentNode.end(); ++edgeIt) {
	//			
	//			//Set maxvalue to cost
	//			int currentCost = std::numeric_limits<int>::max();

	//			//Get connected room
	//			auto &connectedNode = edgeIt->to();
	//			
	//			//Calculate cost
	//			currentCost = cost[currentNode].second + edgeIt->weight;

	//			//Compare costs
	//			//-Find node in cost map
	//			std::map<map::map_node, std::pair<map::map_node, int>>::iterator costIt = cost.find(connectedNode);

	//			//-If node exists in cost map
	//			if (costIt != cost.end())
	//			{
	//				//-If cost was higher than current cost, replace
	//				if (cost[connectedNode].second > currentCost) {
	//					cost[connectedNode] = std::pair{ currentNode, currentCost };
	//				}
	//			}
	//			else {
	//				//-Else place new in cost map
	//				cost[connectedNode] = std::pair{ currentNode, currentCost };
	//			}
	//		}

	//		// Set lowestcost again to maxvalue to compare it with other values
	//		int lowestCost = std::numeric_limits<int>::max();

	//		//Foreach item pair in cost
	//		for (auto costItr = cost.begin(); costItr != cost.end(); ++costItr) {
	//			//If the value is lower than lowestCost and the room isn't in visited anymore, 
	//			//set currentRoom to x.key and lowestCost to the cost of x.key
	//			//x is a node
	//			auto &x = *costItr;

	//			//-If node doesnt exist in cosstmap
	//			if (std::find(visited.begin(), visited.end(), x.second.first) == visited.end()) {
	//				//And if currentcost is less than lowestcost
	//				if (x.second.second < lowestCost) {
	//					//Replace currentNode
	//					//currentNode = x.first;
	//					auto& a = x.first;
	//					lowestCost = x.second.second;
	//				}
	//			}
	//		}

	//		//Remove currentNode and add to visited
	//		RemoveMapNodeFromVector(unvisited, currentNode);
	//		visited.push_back(currentNode);
	//	}

	//	//TODO: Clean discovery animations ("Tagged")

	//	map::map_node &reverse = endRoom;
	//	while (true) {

	//		//TODO: Draw route animation

	//		reversePath.push_back(reverse);
	//		auto& reverseCost = cost[reverse];
	//		//reverse = reverseCost.first;
	//		auto& b = reverseCost.first;
	//	}

	//	std::reverse(reversePath.begin(), reversePath.end());
	//	return reversePath;
	//}

	//void RemoveMapNodeFromVector(std::vector<kmint::map::map_node> &vector, kmint::map::map_node & mapNode)
	//{
	//	//Remove currentRoom from unvisited and add to visited
	//	std::vector<map::map_node>::iterator it = std::find(vector.begin(), vector.end(), mapNode);
	//	if (it != vector.end()) {
	//		vector.erase(it);
	//	}
	//}



	// namespace kmint
}