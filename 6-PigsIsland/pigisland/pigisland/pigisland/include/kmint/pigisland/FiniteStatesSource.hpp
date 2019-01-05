#ifndef PIGISLAND_FINITESTATESSOURCE_HPP
#define PIGISLAND_FINITESTATESSOURCE_HPP

#include "kmint/play.hpp"
#include "SharkSwimmingState.hpp"
#include "SharkHuntingState.hpp"
#include "SharkTiredState.hpp"

namespace kmint {
	namespace pigisland {
		class FiniteStatesSource {
		public:
			explicit FiniteStatesSource() {
				_sharkHuntingState = new SharkHuntingState();
				_sharkSwimmingState = new SharkSwimmingState();
				_sharkTiredState = new SharkTiredState();
			}

			~FiniteStatesSource()
			{
				delete _sharkHuntingState;
				delete _sharkSwimmingState;
				delete _sharkTiredState;
			}

			SharkSwimmingState* GetSharkSwimmingState() const
			{
				return _sharkSwimmingState;
			}

			SharkHuntingState* GetSharkHuntingState(kmint::play::map_bound_actor* actor)
			{
				return _sharkHuntingState;
			}

			SharkTiredState* GetSharkTiredState() const
			{
				return _sharkTiredState;
			}

		private:
			SharkSwimmingState* _sharkSwimmingState;
			SharkHuntingState* _sharkHuntingState;
			SharkTiredState* _sharkTiredState;
		};
	}
}
#endif
