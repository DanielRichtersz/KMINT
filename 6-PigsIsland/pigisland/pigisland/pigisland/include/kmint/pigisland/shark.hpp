#ifndef KMINT_PIGISLAND_SHARK_HPP
#define KMINT_PIGISLAND_SHARK_HPP

#include "kmint/map/map.hpp"
#include "kmint/play.hpp"
#include "kmint/primitives.hpp"

namespace kmint {
	namespace pigisland {

		class shark : public play::map_bound_actor {
		public:
			shark(kmint::map::map_graph &g);
			ui::drawable const &drawable() const override { return drawable_; }
			bool incorporeal() const override { return false; }
			scalar radius() const override { return 16.0; }
			void act(delta_time dt) override;
			scalar range_of_perception() const override { return 100.0; };
			bool perceptive() const override { return true; };
			const map::map_node* getRestingPlace() { return resting_place_; }
			void shark::resetPigsEaten() { pigsEaten = 0; }
			int getPigsEaten() { return pigsEaten; }
			void increaseGenerations() { generations++; }
			int getGenerations() { return generations; };

		private:
			play::image_drawable drawable_;
			map::map_graph *map_;
			map::map_node const *resting_place_;
			delta_time t_since_move_{};
			int pigsEaten = 0;
			int generations = 1;
		};

	} // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_SHARK_HPP */