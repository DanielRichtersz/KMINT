#ifndef KMINT_PIGISLAND_BOATSTATECONDITIONS_HPP
#define KMINT_PIGISLAND_BOATSTATECONDITIONS_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
#include "FiniteStatesSource.hpp"
#include <iostream>

namespace kmint
{
	namespace pigisland
	{
		class BoatStateConditions {
		public:
			BoatStateConditions() : _finiteStateSource{ new FiniteStatesSource() } {}

			~BoatStateConditions()
			{
				delete _finiteStateSource;
			}

			BoatBaseState* GetBoatState(kmint::play::map_bound_actor* actor)
			{
				// Als boat binnen 50 pixels is, retourneer SharkFearedState

				// Als pig binnen 100 pixels i, retourneer SharkHuntingState

				// Als shark 0 endurance heeft, retourneer 

				return _finiteStateSource->GetBoatFloatState();
			}

		private:
			kmint::pigisland::FiniteStatesSource* _finiteStateSource;
		};

	}
}

#endif

