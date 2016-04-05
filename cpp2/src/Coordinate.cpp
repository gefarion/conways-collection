#include "Coordinate.h"

namespace conway {

	Coordinate::Coordinate(float axisX, float axisY) {
		_axisX = axisX;
		_axisY = axisY;
	}

	float Coordinate::axisX() {
		return _axisX;
	}

	float Coordinate::axisY() {
		return _axisY;
	}

}