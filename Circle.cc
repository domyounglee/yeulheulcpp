#include <iostream>

#include "Circle.h"
using namespace std;
Circle::Circle(int x, int y,int r):pos(x,y){
	if(r<0){
		cout<<"set the radius positive"<<endl;
		radius=0;
	}
	
	radius = r;

}

void Circle::ShowCirInfo() const{

	cout<<"radius : "<<radius<<endl;
	cout<<"["<<pos.GetX()<<", "<<pos.GetY()<<"]"<<endl;
}