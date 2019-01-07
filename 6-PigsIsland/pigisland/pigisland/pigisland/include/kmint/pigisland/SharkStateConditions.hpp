#ifndef KMINT_PIGISLAND_SHARKSTATECONDITIONS_HPP
#define KMINT_PIGISLAND_SHARKSTATECONDITIONS_HPP
#include "node_algorithm.hpp"
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
					return _finiteStateSource->GetSharkTiredState();
				}

				// If the shark perceives anything
				if (actor->num_perceived_actors() != 0)
				{
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
				// Als boat binnen 50 pixels is, retourneer SharkFearedState

				// Als pig binnen 100 pixels i, retourneer SharkHuntingState




				return _finiteStateSource->GetSharkSwimmingState();
			}

		private:
			kmint::pigisland::FiniteStatesSource* _finiteStateSource;
		};

	}
}

#endif

