#ifndef __CIRCLE__
#define __CIRCLE__

#include "Point.h"

class Circle{
	private:
		Point pos;
		int radius;
	public:
		Circle(int x, int y,int r);
		void ShowCirInfo() const;
};
#endif