#ifndef KMINT_PIGISLAND_SHARKHUNTINGSTATE_HPP
#define KMINT_PIGISLAND_SHARKHUNTINGSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"

namespace kmint
{
	namespace pigisland
	{
		class SharkHuntingState : public kmint::pigisland::SharkBaseState {
		public:
			SharkHuntingState() = default;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				//std::cout << "Shark is hunting a pig" << std::endl;
				//Set Target location
				//math::vector2d targetLocation =

				float lowestCost = 0;
				const map::map_node* targetPigLocation = nullptr;

				//For all actors nearby, see if its pig
				for (auto& it = actor->begin_perceived(); it != actor->end_perceived(); ++it)
				{
					if (it->GetActorType() == play::Pig)
					{
						//Find nearest node to target location
						const map::map_node* nearestNodeToLocation = FindNearestNodeToLocation(actor->graph(), it->location());

						//Calculate cost to get to the nearest node near the location of the pig
						std::vector<const map::map_node*> const targetToPath = AstarPath(actor->graph(), &actor->node(), nearestNodeToLocation );
						
						auto const cost = GetPathTotalCost(targetToPath);

						//If cost is lower, replace target
						if ( cost < lowestCost)
						{
							lowestCost = cost;
							targetPigLocation = nearestNodeToLocation;
						}
					}
				}

				//Find nearest node to target
				if (targetPigLocation != nullptr)
				{
					actor->destinationNode(*targetPigLocation);
				}
				else
				{
					actor->destinationNode(random_adjacent_node(actor->node()));
				}
			}
		};

	}
}

#endif

