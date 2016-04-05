#include "OrganicMatter.h"
#include "Organism.h"

namespace conway {

	OrganicMatter& OrganicMatter::instance() {
		static OrganicMatter instance;
		return instance;
	}

	bool OrganicMatter::isAlive() {
		return false;
	}

	Substance& OrganicMatter::overturn() {
		return Organism::instance();
	}

}
