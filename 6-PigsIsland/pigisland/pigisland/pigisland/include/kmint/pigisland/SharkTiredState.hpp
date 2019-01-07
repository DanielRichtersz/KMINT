#ifndef KMINT_PIGISLAND_SHARKTIREDSTATE_HPP
#define KMINT_PIGISLAND_SHARKTIREDSTATE_HPP
#include "node_algorithm.hpp"
#include "SharkBaseState.hpp"
#include "kmint/play.hpp"
#include <iostream>
namespace kmint
{
	namespace pigisland
	{
		class SharkTiredState : public kmint::pigisland::SharkBaseState {
		public:
			SharkTiredState() = default;;

			void Execute(kmint::play::map_bound_actor* actor) override
			{
				_reachedRestingPlace = math::distance(actor->location(), find_shark_resting_place(actor->graph()).location()) == 0;
				if (_reachedRestingPlace)
				{
					actor->setEndurance(actor->getMaxEndurance());
					//std::cout << "Shark is resting";
				}
				else
				{
					//std::cout << "Shark is tired, returning to resting place" << std::endl;
					actor->destinationNode(find_shark_resting_place(actor->graph()));
				}
			}

		private:
			bool _reachedRestingPlace = false;
		};

	}
}

#endif

