#pragma once
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

		template<class T>
		class BaseEnduranceState : public state<kmint::play::graph_bound_actor<T>> {
		public:
			BaseEnduranceState(kmint::play::graph_bound_actor<T> actor) : state<kmint::play::graph_bound_actor<T>>{ actor } {}
		};


	}
}
