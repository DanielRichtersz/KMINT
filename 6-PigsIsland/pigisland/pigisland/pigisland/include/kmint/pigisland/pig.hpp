#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include "FDE/FDEPig.hpp"
#include "Flocking/FlockingPig.hpp"

namespace kmint {
	namespace pigisland {

		class pig : public play::free_roaming_actor {
		public:
			explicit pig(math::vector2d location);
			explicit pig(math::vector2d location, FlockingPig genes);
			const ui::drawable &drawable() const override { return drawable_; }
			void move(math::vector2d delta) { location(location() + delta); }
			void act(delta_time dt) override;
			bool perceptive() const override { return true; }
			scalar range_of_perception() const override { return 100.0f; }
			FlockingPig getPig() override { return _FlockingPig; };
			bool isFreeRoamingActor() override { return true; };
			void setGenes(pigisland::FlockingPig gene) override { _FlockingPig = gene; };
			void reset() override;
			math::vector2d heading() const override { return _heading; };

		private:
			play::image_drawable drawable_;
			math::vector2d _heading;
			FlockingPig _FlockingPig;
			FDEPig _FDEPig;
		};

	} // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
