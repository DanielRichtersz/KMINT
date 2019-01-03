#include "kmint/math/vector2d.hpp"

namespace kmint {
	namespace pigisland {
		class FDEPig {
		public:
			FDEPig() {}
			//Voorlopig geen acceleration
			void setMass(float newMass) { _mass = newMass; }
			float getMass() { return _mass; }

			math::vector2d getAcceleration() { return _force / _mass; }
			void setAcceleration(math::vector2d newAcceleration) { _acceleration = newAcceleration; }
			//math::vector2d getVelocity() { return _velocity; }
			math::vector2d getForce() { return _force; }
			math::vector2d getPosition() { return _position; }

		private:
			float _mass;
			math::vector2d _force;
			math::vector2d _acceleration;
			//math::vector2d _velocity;
			math::vector2d _position;
		};
	}
}