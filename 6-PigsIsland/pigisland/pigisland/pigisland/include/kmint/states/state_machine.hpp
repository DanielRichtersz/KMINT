#include "kmint/map/map.hpp"
#include "kmint/pigisland/boat.hpp"

namespace kmint {
	namespace pigisland {
		template <class T>
		class state {
		public:
			T &instance;

			virtual state<T> replaceState();
			virtual const map::map_node* Execute(T* actor);
		};


		//template <class Owner>
		//class StateMachine {
		//private:
		//	Owner &instance;
		//	state<Owner> *state;

		//public:
		//	StateMachine(T t*) : instance(*t) {}

		//	void set_state(T *t) {
		//		if (state) != nullptr{ delete state;  }
		//		state = t;
		//	}
		//};

		class BaseEnduranceState : public state<kmint::play::map_bound_actor> {
		public:
			BaseEnduranceState(kmint::play::map_bound_actor actor) : state<kmint::play::map_bound_actor>{ actor } {}
		};


	}
}
