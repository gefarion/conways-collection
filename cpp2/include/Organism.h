#ifndef ORGANISM_H
#define ORGANISM_H

#include "Substance.h"

namespace conway {
	class OrganicMatter;

	class Organism : public Substance {

	public:

		static Organism& instance();

		bool isAlive();

		Substance& overturn();
	};
}

#endif
