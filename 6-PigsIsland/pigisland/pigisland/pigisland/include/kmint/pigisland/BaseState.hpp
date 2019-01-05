#ifndef KMINT_PIGISLAND_STATE_HPP
#define KMINT_PIGISLAND_STATE_HPP
#include "kmint/map/map.hpp"


template <class T>
class state {
public:
	T &instance;

	virtual state<T> replaceState();
	virtual void* Execute(T* actor);
};
#endif
