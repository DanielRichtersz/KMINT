#ifndef KMINT_PIGISLAND_BASEENDURANCESTATE_HPP
#define KMINT_PIGISLAND_BASEENDURANCESTATE_HPP

#include "kmint/map/map.hpp"
#include "../states/state_machine.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class BaseEnduranceState : public state<kmint::play::map_bound_actor> {
		public:
			BaseEnduranceState() {};

			void setActor(kmint::play::map_bound_actor* _actor) { actor = _actor; }


			void setEndurance(int remainingEndurance)
			{
				_remainingEndurance = remainingEndurance;
			};

			int increaseEndurance(int amount)
			{
				_remainingEndurance = (_remainingEndurance + amount) <= _maxEndurance
					? _remainingEndurance += amount
					: _maxEndurance; return _remainingEndurance;
			}
				
			int getEndurance()
			{
				return _remainingEndurance;
			}

		protected:
			kmint::play::map_bound_actor * actor;
			int _maxEndurance = 100;
			int _remainingEndurance = 100;
		};
	}
}

#endif

