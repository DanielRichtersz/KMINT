#ifndef KMINT_PIGISLAND_STATE_HPP
#define KMINT_PIGISLAND_STATE_HPP

template <class T>
class state {
public:
	virtual state<T> replaceState();
	virtual void Execute(T* actor);
};
#endif
