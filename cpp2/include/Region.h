#ifndef REGION_H
#define REGION_H

#include "Coordinate.h"
#include "Substance.h"
#include <list>
#include "WorldSurface.h"

namespace conway {

	class Region {

	private:

		Coordinate* _location;
		Substance* _substance;
		WorldSurface* _surface;

	public:

		Region(Coordinate *location, WorldSurface *surface);

		Coordinate* location();

		Substance* substance();

		WorldSurface* surface();

		Region* substance(Substance *substance);

		bool hasLife();

		std::list<Region*>* neighboors();

		Region* randomize();

		Region* toggle();

	};
}

#endif 
