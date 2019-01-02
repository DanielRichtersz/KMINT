#include "kmint/pigisland/node_algorithm.hpp"
#include "kmint/pigisland/resources.hpp"
#include "kmint/random.hpp"
#include "kmint/pigisland/FDE/FDEPig.hpp"

namespace kmint {
	namespace pigisland {
		class FDEPIG {
			FDEPig::FDEPig() {
				_attractionToBoat = random_scalar(-1, 1);
				_attractionToShark = random_scalar(-1, 1);
				_cohesion = random_scalar(0, 1);
				_seperation = random_scalar(0, 1);
				_alignment = random_scalar(0, 1);
			}
		};
	} // namespace pigisland
} // namespace kmint
