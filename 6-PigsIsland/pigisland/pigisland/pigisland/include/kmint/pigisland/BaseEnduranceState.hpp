#include "kmint/map/map.hpp"
#include "kmint/pigisland/boat.hpp"

class BaseEnduranceState : public state<> {
public:
	int increaseEndurance(int amount) { _endurance += amount; return _endurance; }
	int getEndurance() { return _endurance; }

	const map::map_node* Execute(T* actor) {
		
	}

private:
	int _endurance;
};

