#include "World.h"

namespace conway {

	World::World(int rows, int cols) {
		_board = new Board(rows, cols);
		_surrogate = new Board(rows, cols);
	}

	World::~World() {
		delete _board;
		delete _surrogate;
	}

	int World::rows() const {
		return _board->rows();
	}

	int World::cols() const {
		return _board->cols();
	}

	void World::evolve() {
		for (int i = 0; i < _board->rows(); i += 1) {
			for (int j = 0; j < _board->cols(); j += 1) {
				int neighbors = neighborsOf(i, j);
				int value = _board->valueIn(i, j, 0);
				if (neighbors == 3) {
					value = 1;
				}
				else if (neighbors != 2) {
					value = 0;
				}
				_surrogate->writeIn(i, j, value);
			}
		}
		swap();
	}

	void World::toggle(int row, int col) {
		if (_board->isInRange(row, col)) {
			int value = _board->valueIn(row, col, 0);
			_board->writeIn(row, col, 1 - value);
		}
	}

	void World::print() const {
		_board->print();
	}

	void World::evolveAndPrint(int repetitions) {
		for (int i = 0; i < repetitions; i += 1) {
			evolve();
			print();
		}
	}

	void World::swap() {
		Board* tmp = _surrogate;
		_surrogate = _board;
		_board = tmp;
	}

	int World::neighborsOf(int row, int col) {
		int value = - _board->valueIn(row, col, 0);
		for (int i = -1; i < 2; i += 1) {
			for (int j = -1; j < 2; j += 1) {
				value += _board->valueIn(row + i, col + j, 0);
			}
		}
		return value;
	}
}
