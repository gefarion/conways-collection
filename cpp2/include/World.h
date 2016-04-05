#ifndef WORLD_H
#define WORLD_H

#include "WorldSurface.h"

namespace conway {

	class World {

	private:

		unsigned int _age;
		WorldSurface *_surface;

	public:

		World(WorldSurface *surface);

		unsigned int age();
	};

}

#endif 
