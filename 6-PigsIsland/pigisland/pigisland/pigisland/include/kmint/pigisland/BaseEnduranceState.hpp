#ifndef KMINT_PIGISLAND_BASEENDURANCESTATE_HPP
#define KMINT_PIGISLAND_BASEENDURANCESTATE_HPP

#include "../states/state_machine.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class BaseEnduranceState : public state<kmint::play::map_bound_actor> {
		public:
			BaseEnduranceState() {};

			void Execute(kmint::play::map_bound_actor* actor) override {};

			void setEndurance(int remainingEndurance)
			{
				_remainingEndurance = remainingEndurance;
			};

			void increaseEndurance(int amount)
			{
				_remainingEndurance = (_remainingEndurance + amount) <= _maxEndurance
					? _remainingEndurance += amount
					: _maxEndurance; 
				std::cout << "Endurance: " << _remainingEndurance << std::endl;
			}

			void moveEnduranceEffect()
			{
				_remainingEndurance = _remainingEndurance <= 0 ? 0 : _remainingEndurance - 10;
				std::cout << "Endurance: " << _remainingEndurance << std::endl;
			}
				
			int getEndurance()
			{
				return _remainingEndurance;
			}

		protected:
			int _maxEndurance = 100;
			int _remainingEndurance = 100;
		};

	}
}

#endif

