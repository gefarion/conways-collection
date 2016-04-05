#ifndef PATTERN_LOADER_H
#define PATTERN_LOADER_H

#include "World.h"

namespace conway {

	class PatternLoader {

	public:

		void loadOn(char *filename, World &world) const;

	};
}

#endif
