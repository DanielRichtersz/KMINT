#ifndef KMINT_PIGISLAND_BOATBASESTATE_HPP
#define KMINT_PIGISLAND_BOATBASESTATE_HPP

#include "kmint/play.hpp"
#include "BaseState.hpp"

namespace kmint
{
	namespace pigisland
	{
		class BoatBaseState : public state<kmint::play::map_bound_actor> {
		protected:
			~BoatBaseState() = default;
		public:
			BoatBaseState() = default;
			virtual void Execute(kmint::play::map_bound_actor* actor) {};
		};

	}
}

#endif

