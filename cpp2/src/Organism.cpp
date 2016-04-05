#include "Organism.h"
#include "OrganicMatter.h"

namespace conway {

	Organism& Organism::instance() {
		static Organism instance;
		return instance;
	}

	bool Organism::isAlive() {
		return true;
	}

	Substance& Organism::overturn() {
			return OrganicMatter::instance();
	}

}
