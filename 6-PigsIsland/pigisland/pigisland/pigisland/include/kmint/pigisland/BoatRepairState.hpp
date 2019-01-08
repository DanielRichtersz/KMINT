#ifndef KMINT_PIGISLAND_BOATREPAIRSTATE_HPP
#define KMINT_PIGISLAND_BOATREPAIRSTATE_HPP
#include "node_algorithm.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class BoatRepairState : public kmint::pigisland::BoatBaseState {
		public:
			BoatRepairState() { _mooringDestination = nullptr; };

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				if (_mooringDestination == nullptr)
				{
					//Find best mooring place
					//TODO: For now random
					_mooringDestination = &find_random_mooring_place(actor->graph());
				}
				if (math::distance(actor->node().location(), _mooringDestination->location()) == 0)
				{
					actor->increaseEndurance(actor->getMaxEndurance());
				}
				else
				{
					actor->destinationNode(*_mooringDestination);
				}
			}
		private:
			const map::map_node* _mooringDestination;
		};

	}
}

#endif

