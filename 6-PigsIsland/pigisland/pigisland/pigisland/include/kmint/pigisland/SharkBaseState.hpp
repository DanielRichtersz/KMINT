#ifndef KMINT_PIGISLAND_SHARKBASESTATE_HPP
#define KMINT_PIGISLAND_SHARKBASESTATE_HPP

#include "kmint/play.hpp"
#include "BaseState.hpp"

namespace kmint
{
	namespace pigisland
	{
		class SharkBaseState : public state<kmint::play::map_bound_actor> {
		protected:
			~SharkBaseState() = default;
		public:
			SharkBaseState() = default;
			virtual void Execute(kmint::play::map_bound_actor* actor) { };

		};

	}
}

#endif

