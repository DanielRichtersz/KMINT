#ifndef PIGISLAND_FINITESTATEMACHINE_HPP
#define PIGISLAND_FINITESTATEMACHINE_HPP

#include "BaseEnduranceState.hpp"
#include "SharkStateConditions.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			explicit FiniteStateMachine() 
			{

			}

			void setState(kmint::pigisland::BaseEnduranceState* state) { _currentState = state; }

			kmint::pigisland::BaseEnduranceState* getState() const { return _currentState; }
			SharkBaseState* GetSharkState(kmint::play::map_bound_actor* actor) { return _sharkStateConditions.GetSharkState(actor); }

		private:
			kmint::pigisland::BaseEnduranceState* _currentState;
			SharkStateConditions _sharkStateConditions;

		};
	}
}
#endif
