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
				// Als boat binnen 50 pixels is, retourneer SharkFearedState

				// Als pig binnen 100 pixels i, retourneer SharkHuntingState

				// Als shark 0 endurance heeft, retourneer 
				

				return _finiteStateSource->GetSharkSwimmingState();
			}

		private:
			kmint::pigisland::FiniteStatesSource* _finiteStateSource;
		};

	}
}

#endif

