#ifndef PIGISLAND_FINITESTATEMACHINE_HPP
#define PIGISLAND_FINITESTATEMACHINE_HPP

#include "BaseEnduranceState.hpp"
#include "kmint/play.hpp"
#include "FiniteStatesSource.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			explicit FiniteStateMachine() 
			{

			}

			void setState(kmint::pigisland::BaseEnduranceState* state) { _currentState = state; }

			kmint::pigisland::BaseEnduranceState* getState() const { return _currentState; }

		private:
			kmint::pigisland::BaseEnduranceState* _currentState;
		};
	}
}
#endif
