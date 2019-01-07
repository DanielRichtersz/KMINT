#ifndef PIGISLAND_FINITESTATEMACHINE_HPP
#define PIGISLAND_FINITESTATEMACHINE_HPP

#include "SharkStateConditions.hpp"
#include "BoatStateConditions.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			explicit FiniteStateMachine() 
			{

			}

			SharkBaseState* SetBoatDestination(kmint::play::map_bound_actor* actor) { return _sharkStateConditions.GetSharkState(actor); }
			BoatBaseState* SetSharkDestination(kmint::play::map_bound_actor* actor) { return _boatStateConditions.GetBoatState(actor); }


		private:
			SharkStateConditions _sharkStateConditions;
			BoatStateConditions _boatStateConditions;

		};
	}
}
#endif
