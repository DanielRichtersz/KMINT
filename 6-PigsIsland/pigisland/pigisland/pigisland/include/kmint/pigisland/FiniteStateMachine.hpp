#include "BaseEnduranceState.hpp"
#include "kmint/play.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			explicit FiniteStateMachine(const BaseEnduranceState* base_endurance_state) : _currentState(base_endurance_state) { 
				
			}

			void executeState(kmint::play::map_bound_actor* actor) const { _currentState->Execute(actor); }

		private:
			const kmint::pigisland::BaseEnduranceState* _currentState;
		};
	}
}