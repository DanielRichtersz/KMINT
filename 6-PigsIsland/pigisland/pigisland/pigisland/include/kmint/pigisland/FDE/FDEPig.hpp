#ifndef KMINT_PIGISLAND_FDEPIG_HPP
#define KMINT_PIGISLAND_FDEPIG_HPP

namespace kmint {
	namespace pigisland {

		class FDEPig {
		public:
			FDEPig() {};

			void setAttractionToShark(float newAttraction) { if (newAttraction >= -1 && newAttraction <= 1) { this->_attractionToShark = newAttraction; }; }
			float getAttracktionToShark() { return _attractionToShark; }

			void setAttractionToBoat(float newAttraction) { if (newAttraction >= -1 && newAttraction <= 1) { this->_attractionToBoat = newAttraction; }; }
			float getAttracktionToBoat() { return _attractionToBoat; }

			void setCohesion(float newCohesion) { if (newCohesion >= 0 && newCohesion <= 1) { this->_cohesion = newCohesion; }; }
			float getCohesion() { return this->_cohesion; }

			void setSeperation(float newSeperation) { if (newSeperation >= 0 && newSeperation <= 1) { this->_seperation = newSeperation; }; }
			float getSeperation() { return this->_seperation; }

			void setAlignment(float newAlignment) { if (newAlignment >= 0 && newAlignment <= 1) { this->_alignment = newAlignment; }; }
			float getAlignment() { return this->_alignment; }

		private:
			float _attractionToShark;
			float _attractionToBoat;
			float _cohesion;
			float _seperation;
			float _alignment;
		};

	} // namespace pigisland
} // namespace kmint

#endif /* KMINT_PIGISLAND_FDEPIG_HPP */
