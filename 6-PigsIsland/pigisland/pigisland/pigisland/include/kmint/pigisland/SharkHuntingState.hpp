#ifndef KMINT_PIGISLAND_SHARKHUNTINGSTATE_HPP
#define KMINT_PIGISLAND_SHARKHUNTINGSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkHuntingState : public kmint::pigisland::SharkBaseState {
		public:
			SharkHuntingState(map::map_node* targetNode) : _targetNode(targetNode) { };

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				std::cout << "Shark is hunting a pig" << std::endl;

				//Check if state needs replacing

				//Move actor
				Move(actor);

			}

		private:
			void Move(kmint::play::map_bound_actor* actor)
			{
				if (_targetNode != nullptr)
				{
					actor->destinationNode(_targetNode());
					BaseEnduranceState::moveEnduranceEffect();
				}
			}

			map::map_node* _targetNode;
		};

	}
}

#endif

