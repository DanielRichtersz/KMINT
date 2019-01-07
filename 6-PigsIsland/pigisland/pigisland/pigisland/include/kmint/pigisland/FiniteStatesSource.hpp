#ifndef PIGISLAND_FINITESTATESSOURCE_HPP
#define PIGISLAND_FINITESTATESSOURCE_HPP

#include "SharkSwimmingState.hpp"
#include "SharkHuntingState.hpp"
#include "SharkTiredState.hpp"
#include "shark.hpp"
#include "BoatFloatState.hpp"
#include "BoatRepairState.hpp"

namespace kmint {
	namespace pigisland {
		class shark;
		class FiniteStatesSource {
		public:
			explicit FiniteStatesSource() {
				_sharkHuntingState = new SharkHuntingState();
				_sharkSwimmingState = new SharkSwimmingState();
				_sharkTiredState = new SharkTiredState();
				_boatFloatState = new BoatFloatState();
				_boatRepairState = new BoatRepairState();
			}

			~FiniteStatesSource()
			{
				delete _sharkHuntingState;
				delete _sharkSwimmingState;
				delete _sharkTiredState;
				delete _boatFloatState;
				delete _boatRepairState;
			}

			SharkSwimmingState* GetSharkSwimmingState() const
			{
				return _sharkSwimmingState;
			}

			SharkHuntingState* GetSharkHuntingState() const
			{
				return _sharkHuntingState;
			}

			SharkTiredState* GetSharkTiredState() const
			{
				return _sharkTiredState;
			}

			BoatFloatState* GetBoatFloatState() const
			{
				return _boatFloatState;
			}

			BoatRepairState* GetBoatRepairState() const
			{
				return _boatRepairState;
			}

		private:
			SharkSwimmingState* _sharkSwimmingState;
			SharkHuntingState* _sharkHuntingState;
			SharkTiredState* _sharkTiredState;
			BoatFloatState* _boatFloatState;
			BoatRepairState* _boatRepairState;
		};
	}
}
#endif
