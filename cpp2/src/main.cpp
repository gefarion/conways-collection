#include <iostream> // Include for I/O streams

#include "Coordinate.h"
#include "Region.h"
#include "WorldSurface.h"

using namespace std; // Streams are in the std namespace (standard library)

int main() {

	conway::Coordinate c(10, 12);
	conway::WorldSurface w(10, 10);

	conway::Region r(&c, &w);

	cout << "\n";
	cout << r.location()->axisY();
	cout << "\n";
}
