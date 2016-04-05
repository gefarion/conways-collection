#include <iostream>

#include "World.h"
#include "PatternLoader.h"
#include <cassert>
#include <stdlib.h>

using namespace conway;

int main(int argc, char *argv[]) {
	assert(argc == 4);

	World w = World(atoi(argv[1]), atoi(argv[2]));
	PatternLoader loader;
	loader.loadOn(argv[3], w);

	while (1) {
		w.evolveAndPrint(1);
	}

	return 0;
}
