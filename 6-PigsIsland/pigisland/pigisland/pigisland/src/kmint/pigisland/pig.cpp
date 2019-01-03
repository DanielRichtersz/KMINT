#include "kmint/pigisland/pig.hpp"
#include "kmint/math/angle.hpp"
#include "kmint/math/vector2d.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include <cmath>

namespace kmint {
	namespace pigisland {

		namespace {

			math::vector2d random_vector() {
				auto x = random_scalar(100, 924);
				auto y = random_scalar(50, 728);
				return { x, y };
			}
		} // namespace

		pig::pig(math::vector2d location)
			: free_roaming_actor{ random_vector() }, drawable_{ *this, pig_image() } {}
		//: free_roaming_actor{ random_vector() }, drawable_{ *this, pig_image() }, _FlockingPig(FlockingPig{}), _FDEPig(FDEPig{}) {}

		void pig::act(delta_time dt) {
			
			//pig::move(math::vector2d{ heading().x * _FDEPig.getForce().x, heading().x * _FDEPig.getForce().y });

			//free_roaming_actor::location(math::vector2d{ heading().x * _FDEPig.getForce().x, heading().x * _FDEPig.getForce().y });
			free_roaming_actor::act(dt);
		}
	} // namespace pigisland

} // namespace kmint