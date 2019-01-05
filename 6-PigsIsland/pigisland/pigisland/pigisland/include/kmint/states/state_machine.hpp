#pragma once
#include "kmint/map/map.hpp"
#include "kmint/pigisland/boat.hpp"

namespace kmint {
	namespace pigisland {
		template <class T>
		class state {
		public:
		   state() = default;
			virtual ~state(){};

			virtual state<T> replaceState() { return {}; };
			virtual const map::map_node* Execute(T* actor){ return nullptr;};
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
			BaseEnduranceState() {};
			state<kmint::play::graph_bound_actor<T>> replaceState() override
			{
				if(actor.location().x() == 0)
				{
					//next state
				}
				//else do nothing
				return {	};
			};
			const map::map_node* Execute(kmint::play::graph_bound_actor<T>* actor) override;

			void setActor(kmint::play::graph_bound_actor<T> _actor) { actor = _actor; }
			void setEndurance(int _remainingEndurance) { remainingEndurance = _remainingEndurance; };

		private:
			kmint::play::graph_bound_actor<T> actor;
			int remainingEndurance;
		};

		template <class T>
		const map::map_node* BaseEnduranceState<T>::Execute(kmint::play::graph_bound_actor<T>* actor)
		{
			//check endurance
			//check next location

			return nullptr;
		}
	}
}
