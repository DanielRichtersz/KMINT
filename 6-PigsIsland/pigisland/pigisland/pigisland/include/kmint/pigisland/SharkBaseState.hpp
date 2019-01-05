#ifndef KMINT_PIGISLAND_SHARKBASESTATE_HPP
#define KMINT_PIGISLAND_SHARKBASESTATE_HPP


#include "BaseEnduranceState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkBaseState : public kmint::pigisland::BaseEnduranceState {
		protected:
			~SharkBaseState() = default;
		public:
			SharkBaseState() = default;
			virtual void Execute(kmint::play::map_bound_actor* actor) {};

		};

	}
}

#endif

