#include <iostream>
#include "Point.h"
using namespace std;


Point::Point(int xpos, int ypos){
	if(xpos<0 || ypos<0){
		cout<<"wrong range"<<endl;


	}
	x=xpos;
	y=ypos;

}

int Point::GetX() const{
	return x;
}

int Point::GetY() const{
	return y;
}

bool Point::SetX(int xpos){
	if(xpos<0){
		cout<<"wrong range "<<endl;
		return false;
	}
	x= xpos;
	return true;
}

bool Point::SetY(int ypos){
	if(ypos<0){
		cout<<"wrong range "<<endl;
		return false;
	}
	y= ypos;
	return true;
}


