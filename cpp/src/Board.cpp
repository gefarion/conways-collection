#include "Board.h"
#include <stdio.h>

namespace conway {

	Board::Board(int rows, int cols) : _rows(rows), _cols(cols) {
		_matrix = new int[rows * cols];
		for (int i = 0; i < size(); i += 1) {
			_matrix[i] = 0;
		}
	}

	Board::~Board() {
		delete[] _matrix;
	}

	bool Board::isInRange(int row, int col) const {
		return 0 <= row && 0 <= col && row < _rows && col < _cols;
	}

	void Board::writeIn(int row, int col, int value) {
		if (isInRange(row, col)) {
			_matrix[row * _cols + col] = value;
		}
	}

	int Board::valueIn(int row, int col, int ifInvalid=0) const {
		if (isInRange(row, col)) {
			return _matrix[row * _cols + col];
		}
		return ifInvalid;
	}

	int Board::rows() const {
		return _rows;
	}

	int Board::cols() const {
		return _cols;
	}

	void Board::print() const {
		for (int i = 0; i < _rows; i += 1) {
			for (int j = 0; j < _cols; j += 1) {
				printf("%d", valueIn(i, j, -1));
			}
			printf("\n");
		}
	}

	int Board::size() const {
		return _rows * _cols;
	}
}
