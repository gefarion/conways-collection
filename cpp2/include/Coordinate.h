#ifndef COORDINATE_H
#define COORDINATE_H

namespace conway {
	
	class Coordinate {

	private:

		double _axisX;
		double _axisY;

	public:

		Coordinate(float axisX, float axisY);
		
		float axisX();
			
		float axisY();
	};
}

#endif