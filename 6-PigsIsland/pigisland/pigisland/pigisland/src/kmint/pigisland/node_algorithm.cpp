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

	std::vector<map::map_node> DijkstraShortestPath(map::map_graph const &graph, map::map_node& startNode, map::map_node &endRoom) {
		std::map<map::map_node, std::pair<map::map_node, int>> cost;
		std::vector<map::map_node&> visited;
		std::vector<map::map_node&> unvisited;
		std::vector<map::map_node&> reversePath;

		map::map_node& currentNode = startNode;

		unvisited.push_back(currentNode);
		for (auto i = 0; i < graph.num_nodes(); ++i) {
			unvisited.push_back(graph[i].~basic_node);
		}

		//Add startroom to cost with a cost of 0


		//Add startroom to cost, with a cost of 0
		reversePath.push_back(startNode);

		for (auto it = unvisited.begin(); it != unvisited.end(); it++) {
			
		}
	} 
	// namespace kmint
}