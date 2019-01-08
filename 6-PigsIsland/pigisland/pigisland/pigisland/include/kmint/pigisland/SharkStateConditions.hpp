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
				shark& sharkActor = dynamic_cast<shark &>(*actor);

				// Als shark 0 endurance heeft, retourneer SharkTiredState
				if (actor->getEndurance() <= 0)
				{
					sharkActor.resetFleeing();
					return _finiteStateSource->GetSharkTiredState();
				}

				if (sharkActor.isFleeing())
				{
					if (sharkActor.stepsSetWhileFleeing() < 11)
					{
						return _finiteStateSource->GetSharkSwimmingState();
					}
				}

				// If the shark perceives anything
				if (actor->num_perceived_actors() != 0)
				{
					sharkActor.resetFleeing();
					for (auto& it = actor->begin_perceived(); it != actor->end_perceived(); ++it)
					{
						// If its a boat, flee
						if (actor->GetActorType() == play::Boat)
						{
							int distancetoBoat = math::distance(actor->location(), it->location());
							if (abs(distancetoBoat) < 50)
							{
								return _finiteStateSource->GetSharkSwimmingState();
							}
						}

						// Else hunt the perceived actor
						std::cout << "Shark goes hunting";
						return _finiteStateSource->GetSharkHuntingState();
					}
				}

				return _finiteStateSource->GetSharkSwimmingState();
			}

		private:
			kmint::pigisland::FiniteStatesSource* _finiteStateSource;
		};

	}
}

#endif

