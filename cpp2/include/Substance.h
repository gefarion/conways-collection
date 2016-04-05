#ifndef SUBSTANCE_H
#define SUBSTANCE_H

namespace conway {

	class Substance {

	public:

		virtual bool isAlive() = 0;

		virtual Substance& overturn() = 0;
	};
}

#endif
