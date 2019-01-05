#ifndef KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP
#define KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP

#include "kmint/map/map.hpp"
#include "../states/state_machine.hpp"
#include "SharkBaseState.hpp"
#include "BaseState.hpp"
#include "kmint/play.hpp"
#include "shark.hpp"
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
				std::cout << "Hello World" << std::endl;
			}

		};

	}
}

#endif

