#include "WorldSurface.h"
#include "Region.h"

namespace conway {

	WorldSurface::WorldSurface(unsigned int width, unsigned int height) : _regions(width * height) {
		_width = width;
		_height = height;

		for (unsigned int i = 0; i < width; ++i) {
			for (unsigned int j = 0; j < height; ++j) {
				_regions[i * width + j] = new Region(new Coordinate(i, j), this);
			}
		}
	}

	Region* WorldSurface::regionInXY(int x, int y) {

		x = (x + _width) % _width;
		y = (y + _height) % _height;

		return _regions[x * _width + y];
	}

	std::list<Region*> *WorldSurface::neighborsOf(Region *region) {
		std::list<Region*> *regions = new std::list<Region*>;
		Coordinate* coordinate = region->location();

		// Cambiar por una lista de pares
		#define push_neighboor(x, y) regions->push_back(this->regionInXY(coordinate->axisX() - x, coordinate->axisY() - y))

		push_neighboor(0, -1);
		push_neighboor(0, 1);

		push_neighboor(-1, -1);
		push_neighboor(-1, 0);
		push_neighboor(-1, 1);

		push_neighboor(1, -1);
		push_neighboor(1, 0);
		push_neighboor(1, 1);

		return regions;
	}

	Region* WorldSurface::regionAt(Coordinate *coordinate) {
		return this->regionInXY(coordinate->axisX(), coordinate->axisY());
	}

	WorldSurface* WorldSurface::apply(void *func(Region*)) {
		for (unsigned int i = 0; i < (_width * _height); ++i) {
			func(_regions[i]);
		}
		return this;
	}

}