#include "PatternLoader.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

namespace conway {
	void PatternLoader::loadOn(char *filename, World &world) const {

		string line;
		ifstream file(filename);

		int row = world.rows() / 6;
		int col_padding = world.cols() / 6;

		assert(file.is_open());
    	while (getline(file, line) ){
      		if (line[0] == '!') continue;

      		for (int i = 0; i < line.size(); ++i) {
      			if (line[i] == 'O') world.toggle(row, i + col_padding);
      		}
      		row++;
    	}

    	file.close();
	}
}