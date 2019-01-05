#include "BaseEnduranceState.hpp"
#include "kmint/play.hpp"
#include "FiniteStatesSource.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			explicit FiniteStateMachine() : _currentState{} {

			}

			void setState(kmint::pigisland::BaseEnduranceState* state)
			{
				_currentState = state;
			}

			kmint::pigisland::BaseEnduranceState* getState()
			{
				return _currentState;
			}

			kmint::pigisland::FiniteStatesSource finiteStateSource()
			{
				return _finiteStateSource;
			}

			void executeState(kmint::play::map_bound_actor* actor) const { if (_currentState != nullptr) { _currentState->Execute(actor); } }

		private:
			kmint::pigisland::BaseEnduranceState* _currentState;
			kmint::pigisland::FiniteStatesSource _finiteStateSource;
		};
	}
}
