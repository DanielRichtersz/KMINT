#ifndef KMINT_PLAY_GRAPH_BOUND_ACTOR_HPP
#define KMINT_PLAY_GRAPH_BOUND_ACTOR_HPP

#include "kmint/map/map.hpp"
#include "kmint/math/vector2d.hpp"
#include "kmint/play/actor.hpp"

namespace kmint::play {

template <typename Graph> class graph_bound_actor : public actor {
public:
  using node_type = typename Graph::node_type;
  using edge_type = typename node_type::edge_type;
  graph_bound_actor(Graph const &graph, node_type const &initial_node)
      : graph_{&graph}, node_{&initial_node} {};
  math::vector2d location() const override { return node_->location(); }

  node_type const &node() const noexcept { return *node_; }
  void node(node_type const &n) noexcept { node_ = &n; }
  Graph const &graph() const noexcept { return *graph_; }

    //Movement
    const node_type* const &destinationNode() const noexcept { return _destinationNode; }
    void destinationNode(node_type const &destinationNode) noexcept {
      _destinationNode = &destinationNode;
    }

    //Endurance
    void setEndurance(int remainingEndurance) {
      _remainingEndurance = remainingEndurance;
    };

    void increaseEndurance(int amount) {
      _remainingEndurance = (_remainingEndurance + amount) <= _maxEndurance
                                ? _remainingEndurance += amount
                                : _maxEndurance;
    }

    void moveEnduranceEffect() {
      _remainingEndurance =
          _remainingEndurance <= 0 ? 0 : _remainingEndurance - 1;
      //std::cout << "Endurance: " << _remainingEndurance << std::endl;
    }

    int getEndurance() { return _remainingEndurance; }
    int getMaxEndurance() { return _maxEndurance; }

private:
  Graph const *graph_;
  node_type const *node_;
  node_type const *_destinationNode = nullptr;
  int _maxEndurance = 100;
  int _remainingEndurance = 100;
};

using map_bound_actor = graph_bound_actor<map::map_graph>;

} // namespace kmint::play

#endif
