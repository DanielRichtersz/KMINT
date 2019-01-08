#ifndef KMINT_PIGISLAND_SHARKSTATECONDITIONS_HPP
#define KMINT_PIGISLAND_SHARKSTATECONDITIONS_HPP
#include "SharkBaseState.hpp"
#include "FiniteStatesSource.hpp"
#include <iostream>

namespace kmint
{
	namespace pigisland
	{
		class SharkStateConditions {
		public:
			SharkStateConditions() : _finiteStateSource{ new FiniteStatesSource() } {}

			~SharkStateConditions()
			{
				delete _finiteStateSource;
			}

			SharkBaseState* GetSharkState(kmint::play::map_bound_actor* actor)
			{
				// Als shark 0 endurance heeft, retourneer SharkTiredState
				if (actor->getEndurance() <= 0)
				{
					actor->resetFleeing();
					return _finiteStateSource->GetSharkTiredState();
				}

				if (actor->isFleeing())
				{
					if (actor->stepsSetWhileFleeing() < 11)
					{
						//std::cout << "Steps set while fleeing: " << actor->stepsSetWhileFleeing() << std::endl;
						return _finiteStateSource->GetSharkSwimmingState();
					}
					if (actor->stepsSetWhileFleeing() >= 11)
					{
						actor->resetFleeing();
					}
				}

				/* If the shark perceives anything*/
				if (actor->num_perceived_actors() != 0)
				{
					//sharkActor.resetFleeing();
					for (auto& it = actor->begin_perceived(); it != actor->end_perceived(); ++it)
					{
						// If its a boat, flee
						if (actor->GetActorType() == play::ActorType::Boat || actor->GetActorType() == play::ActorType(2))
						{
							int distancetoBoat = math::distance(actor->location(), it->location());
							if (abs(distancetoBoat) < 50)
							{
								actor->isFleeing();
								std::cout << "Shark: Fleeing" << std::endl;
								return _finiteStateSource->GetSharkSwimmingState();
							}
						}

						//// Else hunt the perceived actor
						return _finiteStateSource->GetSharkHuntingState();
					}
				}

				std::cout << "Shark: Swimming" << std::endl;
				return _finiteStateSource->GetSharkSwimmingState();
			}

		private:
			kmint::pigisland::FiniteStatesSource* _finiteStateSource;
		};

	}
}

#endif

