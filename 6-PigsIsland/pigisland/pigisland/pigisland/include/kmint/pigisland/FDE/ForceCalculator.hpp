#include "kmint/math/vector2d.hpp"

namespace kmint {
	namespace pigisland {
		class ForceCalculator {
		public:
			ForceCalculator() {}
			//Voorlopig geen acceleration
			void setMass(float newMass) { _mass = newMass; }
			float getMass() { return _mass; }

			math::vector2d getAcceleration() { return getMaxVelocity() / _mass; }
			void setAcceleration(math::vector2d newAcceleration) { _acceleration = newAcceleration; }

			math::vector2d getMaxVelocity() {
				math::vector2d velocity{0.0f, 0.0f};

				for (auto &force : _forces)
				{
					velocity += force;
				}

				if (velocity.x() > 100.0f)
				{
					velocity.x(100.0f);
				}
				if (velocity.y() > 100.0f)
				{
					velocity.y(100.0f);
				}

				return velocity; 
			}

			std::vector<math::vector2d> getForces() { return _forces; }
			math::vector2d getPosition() { return _position; }
			void removeAllForces() { _forces.clear(); }

			void addForce(math::vector2d force) { _forces.emplace_back(force); }

		private:
			float _mass{};
			std::vector<math::vector2d>_forces;
			math::vector2d _acceleration;
			math::vector2d _position;
		};
	}
}