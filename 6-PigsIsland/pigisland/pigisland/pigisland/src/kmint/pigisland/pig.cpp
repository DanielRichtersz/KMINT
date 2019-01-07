#include "kmint/pigisland/pig.hpp"
#include "kmint/math/angle.hpp"
#include "kmint/math/vector2d.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include <cmath>
#include <iostream>

namespace kmint {
	namespace pigisland {

		namespace {

			math::vector2d random_vector() {
				auto x = random_scalar(100, 924);
				auto y = random_scalar(50, 728);
				return { x, y };
			}
			math::vector2d random_vector2() {
				auto x = random_scalar(-100, 100);
				auto y = random_scalar(-100, 100);
				return { x, y };
			}
		} // namespace

		pig::pig(math::vector2d location)
			: free_roaming_actor{ random_vector() }, drawable_{ *this, pig_image() } {_FDEPig.setMass(20); }
		pig::pig(math::vector2d location, PigGenes genes)
			: free_roaming_actor{ random_vector() }, drawable_{ *this, pig_image() }, _FlockingPig(genes) {_FDEPig.setMass(20); }

		void pig::act(delta_time dt) {
			//pig::move(math::vector2d{ heading().x * _FDEPig.getForce().x, heading().x * _FDEPig.getForce().y });

			if(isKilled() || isSaved())
			{
				location(math::vector2d{ -500.0f, -500.0f });
				return;
			}

			auto oldLocation = location();

			if(FleeLocation().x() != -1.0f)
			{
				auto fleeLocation = FleeLocation();

				_FDEPig.addForce((fleeLocation - location()) * _FlockingPig.getAttracktionToShark());

				FleeLocation(&math::vector2d{ -1.0f, -1.0f });
			}

			if(SeekLocation().x() != -1.0f)
			{
				auto seekLocation = SeekLocation();

				_FDEPig.addForce((location() - seekLocation) * _FlockingPig.getAttracktionToBoat());

				SeekLocation(&math::vector2d{ -1.0f, -1.0f });
			}

			for ( auto &itr = begin_perceived(); itr != end_perceived(); ++itr)
			{

				_FDEPig.addForce((location() - itr->location()) * _FlockingPig.getCohesion());
				_FDEPig.addForce((itr->location() - location()) * _FlockingPig.getSeperation());
				_FDEPig.addForce(itr->heading() * _FlockingPig.getAlignment());

			}
			auto newLocation = location() + _FDEPig.getAcceleration();
			_heading = _FDEPig.getAcceleration();
			if(newLocation.x() > 928.0f)
			{
				newLocation.x(928.0f);
			}
			if(newLocation.x() < 0.0f)
			{
				newLocation.x(0);
			}

			if(newLocation.y() > 728.0f)
			{
				newLocation.y(728.0f);
			}
			if (newLocation.y() < 0.0f)
			{
				newLocation.y(0.0f);
			}

			_FDEPig.removeAllForces();

			free_roaming_actor::location(newLocation);

			//free_roaming_actor::location(math::vector2d{ heading().x * _FDEPig.getForce().x, heading().x * _FDEPig.getForce().y });
			//free_roaming_actor::act(dt);
		}

		void pig::reset()
		{
			actor::reset();
			location(random_vector());
		}
	} // namespace pigisland

} // namespace kmint