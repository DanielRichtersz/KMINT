template <class T>
class BaseState {
public:
	T &instance;

	virtual state<T> replaceState();
	virtual const map::map_node* Execute(T* actor);
};
