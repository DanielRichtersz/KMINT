#ifndef KMINT_PIGISLAND_STATE_HPP
#define KMINT_PIGISLAND_STATE_HPP

template <class T>
class state {
public:
	virtual void Execute(T* actor) {};
	virtual ~state() {};
	state &operator=(const state& other) =  delete;
	state &operator=(state &&) = delete;
};
#endif
