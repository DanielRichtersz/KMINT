#ifndef KMINT_PIGISLAND_SHARKTIREDSTATE_HPP
#ifndef KMINT_PIGISLAND_SHARKTIREDSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkTiredState : public kmint::pigisland::SharkBaseState {
		public:
			SharkTiredState() = default;;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				std::cout << "Shark is tired, returning to resting place" << std::endl;

				//Check if state needs replacing

				//Move actor
				Move(actor);

			}

		private:
			void Move(kmint::play::map_bound_actor* actor)
			{
				actor->destinationNode(find_shark_resting_place(actor->graph()));
				if (actor->destinationNode() != nullptr)
				{
					std::vector<const map::map_node*> path = DijkstraShortestPath(actor->graph(), &actor->node(), actor->destinationNode());
					const map::map_node* nextNode = path.at(1);
					if (nextNode != nullptr)
					{
						actor->node(nextNode());
						BaseEnduranceState::moveEnduranceEffect();
					}
				}
			}
		};

	}
}

#endif

