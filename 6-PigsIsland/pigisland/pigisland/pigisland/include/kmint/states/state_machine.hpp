#pragma once


namespace kmint {
	namespace pigisland {
		template <class T>
		class state {
		public:
		   state() = default;
			virtual ~state(){};

			virtual state<T> replaceState() { return {}; };
			virtual void Execute(T* actor){};
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

		//class BaseEnduranceState : public state<kmint::play::map_bound_actor> {
		//public:
		//	BaseEnduranceState() {};
		//	virtual state<kmint::play::graph_bound_actor<map::map_graph>> replaceState() override;
		//	//{
		//	//	if(actor->location().x() == 0)
		//	//	{
		//	//		//next state
		//	//	}
		//	//	//else do nothing
		//	//	return {	};
		//	//};
		//	virtual void Execute(kmint::play::map_bound_actor* actor) override;
		//	//{
		//		////check endurance
		//		//if (_remainingEndurance <= 0) {
		//		//	actor->destinationNode(find_shark_resting_place(actor->graph()));
		//		//}

		//		//if (actor->destinationNode() == nullptr)
		//		//{
		//		//	actor->destinationNode(find_random_mooring_place(actor->graph()));
		//		//}

		//		//while (math::distance(actor->destinationNode()->location(), actor->node().location()) == 0)
		//		//{
		//		//	if (math::distance(actor->node().location(), find_shark_resting_place(actor->graph()).location()) == 0)
		//		//	{
		//		//		_remainingEndurance = 100;
		//		//	}
		//		//	actor->destinationNode(find_random_mooring_place(actor->graph()));
		//		//}

		//		//if (actor->destinationNode() != nullptr)
		//		//{
		//		//	// Get pat
		//		//	std::vector<const map::map_node*> tempVector = DijkstraShortestPath(actor->graph(), &actor->node(), actor->destinationNode());

		//		//	// Get next node
		//		//	const map::map_node* nextNode = tempVector.at(1);

		//		//	// Get nodeInfo from next node
		//		//	//const kmint::graph::basic_node<kmint::map::map_node_info> nodeInfo{ nextNode->node_id(),nextNode->location() };
		//		//	actor->node(*nextNode);
		//		//	_remainingEndurance = _remainingEndurance <= 0 ? 0 : this->increaseEndurance(-10);
		//		//	
		//		//}
		//		//std::cout << "Shark endurance: " << _remainingEndurance << std::endl;
		//	//};

		//	void setActor(kmint::play::map_bound_actor* _actor) { actor = _actor; }

		//	void setEndurance(int remainingEndurance)
		//	{
		//		_remainingEndurance = remainingEndurance;
		//	};

		//	int increaseEndurance(int amount)
		//	{
		//		_remainingEndurance = (_remainingEndurance + amount) <= _maxEndurance 
		//		? _remainingEndurance += amount 
		//		: _maxEndurance; return _remainingEndurance;
		//	}

		//private:
		//	kmint::play::map_bound_actor * actor;
		//	int _maxEndurance = 100;
		//	int _remainingEndurance = 100;
		//};

		
	}
}
