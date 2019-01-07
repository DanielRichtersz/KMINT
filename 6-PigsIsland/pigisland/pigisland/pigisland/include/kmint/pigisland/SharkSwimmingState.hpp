#ifndef KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP
#define KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkSwimmingState : public kmint::pigisland::SharkBaseState {
		public:
			SharkSwimmingState() = default;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				std::cout << "Shark is swimming around" << std::endl;

				//Check if state needs replacing

				//Move actor
				Move(actor);
				
			}

		private:
			void Move(kmint::play::map_bound_actor* actor)
			{
				actor->node(random_adjacent_node(actor->node()));
				BaseEnduranceState::moveEnduranceEffect();
			}
		};

	}
}

#endif

