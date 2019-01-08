#ifndef KMINT_PIGISLAND_BOATFLOATSTATE_HPP
#define KMINT_PIGISLAND_BOATFLOATSTATE_HPP
#include "node_algorithm.hpp"
#include "BoatBaseState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class BoatFloatState : public kmint::pigisland::BoatBaseState {
		public:
			BoatFloatState() = default;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				//std::cout << "Boat is floating around" << std::endl;
				//Move actor
				actor->destinationNode(random_adjacent_node(actor->node()));
			}
		};

	}
}

#endif

