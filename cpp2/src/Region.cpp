#include "Region.h"
#include "OrganicMatter.h"
#include "Organism.h"
#include "WorldSurface.h"
#include <stdlib.h>

namespace conway {

	Region::Region(Coordinate *location, WorldSurface *surface) {
		_location = location;
		_surface = surface;
		_substance = &OrganicMatter::instance();
	}

	Coordinate* Region::location() {
		return _location;
	}

	Substance* Region::substance() {
		return _substance;
	}

	Region* Region::substance(Substance *substance) {
		_substance = substance;
		return this;
	}

	WorldSurface* Region::surface() {
		return _surface;
	}

	bool Region::hasLife() {
		return _substance->isAlive();
	}

	std::list<Region*>* Region::neighboors() {
		return _surface->neighborsOf(this);
	}

	Region* Region::randomize() {
		_substance = rand() % 2 == 0
			? (Substance*) &Organism::instance()
			: (Substance*) &OrganicMatter::instance();
		return this;
	}

	Region* Region::toggle() {
		_substance = &(_substance->overturn());
		return this;
	}
}