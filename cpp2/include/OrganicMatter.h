#ifndef ORGANIC_MATTER_H
#define ORGANIC_MATTER_H

#include "Substance.h"

namespace conway {
	class Organism;

	class OrganicMatter : public Substance {

	public:

		static OrganicMatter& instance();

		bool isAlive();

		Substance& overturn();
	};
}

#endif
