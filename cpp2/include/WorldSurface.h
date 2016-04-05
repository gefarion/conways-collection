#ifndef WORLD_SURFACE_H
#define WORLD_SURFACE_H

#include "Substance.h"
#include "Coordinate.h"
#include <vector>
#include <list>

namespace conway {
	class Region;

	class WorldSurface {

	private:

		unsigned int _width;
		unsigned int _height;
		std::vector<Region*> _regions;

	public:

		WorldSurface(unsigned int width, unsigned int height);

		Region* regionInXY(int x, int y);

		Region* regionAt(Coordinate *coordinate);
		
		WorldSurface* apply(void *func(Region*));

		std::list<Region*>* neighborsOf(Region *region);

	};
}

#endif