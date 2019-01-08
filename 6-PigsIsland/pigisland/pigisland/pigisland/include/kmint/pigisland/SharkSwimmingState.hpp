#ifndef KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP
#define KMINT_PIGISLAND_SHARKSWIMMINGSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
namespace kmint
{
	namespace pigisland
	{
		class SharkSwimmingState : public kmint::pigisland::SharkBaseState {
		public:
			SharkSwimmingState() = default;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				//std::cout << "Shark is swimming around" << std::endl;
				//actor->destinationNode(random_adjacent_node(actor->node()));
				actor->destinationNode(find_random_mooring_place(actor->graph()));
			}
		};

	}
}

#endif

