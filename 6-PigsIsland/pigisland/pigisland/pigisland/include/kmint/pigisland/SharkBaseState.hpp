#ifndef KMINT_PIGISLAND_SHARKBASESTATE_HPP
#define KMINT_PIGISLAND_SHARKBASESTATE_HPP

#include "kmint/map/map.hpp"
#include "../states/state_machine.hpp"
#include "BaseEnduranceState.hpp"
#include "kmint/play.hpp"
#include "shark.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkBaseState : public kmint::pigisland::BaseEnduranceState<kmint::pigisland::shark> {
		public:
			SharkBaseState() = default;

		};

	}
}

#endif

