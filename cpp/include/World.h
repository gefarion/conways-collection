#ifndef WORLD_H
#define WORLD_H

#include "Board.h"

namespace conway {

	class World {

	public:

		World(int rows, int cols);

		~World();

		void evolve();

		void toggle(int row, int col);

		int rows() const;

		int cols() const;

		void print() const;

		void evolveAndPrint(int repetitions);

	private:

		void swap();

		int neighborsOf(int row, int col);

		Board* _board;
		Board* _surrogate;
	};
}

#endif
