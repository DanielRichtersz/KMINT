#ifndef KMINT_PIGISLAND_PIG_HPP
#define KMINT_PIGISLAND_PIG_HPP

#include "kmint/play.hpp"
#include "FDE/ForceCalculator.hpp"
#include "Flocking/PigGenes.hpp"

namespace kmint {
	namespace pigisland {

		class pig : public play::free_roaming_actor {
		public:
			explicit pig(math::vector2d location);
			explicit pig(math::vector2d location, PigGenes genes);
			const ui::drawable &drawable() const override { return drawable_; }
			void move(math::vector2d delta) { location(location() + delta); }
			void act(delta_time dt) override;
			bool perceptive() const override { return true; }
			scalar range_of_perception() const override { return 100.0f; }
			PigGenes getPig() override { return _FlockingPig; };
			bool isFreeRoamingActor() override { return true; };
			void setGenes(pigisland::PigGenes gene) override { _FlockingPig = gene; };
			void reset() override;

		private:
			play::image_drawable drawable_;
			PigGenes _FlockingPig;
			ForceCalculator _FDEPig;
		};

	} // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_PIG_HPP */
