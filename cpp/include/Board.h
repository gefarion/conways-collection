#ifndef BOARD_H
#define BOARD_H

namespace conway {

	class Board {

	public:

		Board(int rows, int cols);

		~Board();

		bool isInRange(int row, int col) const;

		void writeIn(int row, int col, int value);

		int valueIn(int row, int col, int ifInvalid) const;

		int rows() const;

		int cols() const;

		void print() const;

	private:

		int size() const;

		int* _matrix;
		int _rows;
		int _cols;
	};
}

#endif
