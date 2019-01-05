#pragma once
#include "kmint/map/map.hpp"
#include "kmint/pigisland/boat.hpp"
#include "kmint/pigisland/node_algorithm.hpp"

namespace kmint {
	namespace pigisland {
		template <class T>
		class state {
		public:
		   state() = default;
			virtual ~state(){};

			virtual state<T> replaceState() { return {}; };
			virtual const void Execute(T* actor){};
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
				if(actor->location().x() == 0)
				{
					//next state
				}
				//else do nothing
				return {	};
			};
			const void Execute(kmint::play::graph_bound_actor<T>* actor) override;

			void setActor(kmint::play::graph_bound_actor<T>* _actor) { actor = _actor; }
			void setEndurance(int remainingEndurance) { _remainingEndurance = remainingEndurance; };
			int increaseEndurance(int amount) { _remainingEndurance = (_remainingEndurance + amount) <= 100 ? _remainingEndurance += amount : 100; return _remainingEndurance; }

		private:
			kmint::play::graph_bound_actor<T>* actor;
			int _maxEndurance = 100;
			int _remainingEndurance;
		};

		template <class T>
		const void BaseEnduranceState<T>::Execute(kmint::play::graph_bound_actor<T>* actor)
		{
			//check endurance
			if (_maxEndurance == 0) {
				actor->destinationNode(find_shark_resting_place(actor->graph()));
			}
			//check next location
			std::vector<const map::map_node*> tempVector = DijkstraShortestPath(actor->graph(), actor->node(), actor->destinationNode());
			const map::map_node* nextNode = tempVector.at(1);
			actor->node(nextNode);
			this->increaseEndurance(-1);
		}
	}
}
