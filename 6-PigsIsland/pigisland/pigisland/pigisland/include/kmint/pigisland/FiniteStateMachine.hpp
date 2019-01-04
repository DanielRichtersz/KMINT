#include <iostream>
#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/shark.hpp"
#include "BaseState.hpp"
#include "BaseEnduranceState.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStateMachine {
		public:
			//FiniteStateMachine(play::map_bound_actor* actor) : _actor(actor) { 
			//	_currentState = _currentState.replaceState();
			//	_currentState.Execute(_actor);
			//}

			//const map::map_node* executeState() { return _currentState.Execute(_actor); }

		private:
			//BaseState _currentState;
			//const play::map_bound_actor* _actor;
		};
	}
}