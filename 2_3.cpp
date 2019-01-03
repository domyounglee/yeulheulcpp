#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct {

	int xpos;
	int ypos;

}Point;

Point& PntAdder(const Point &p1, const Point &p2){
	Point* point = new Point; //heap doesn't disappear when the function close
	point->xpos=p1.xpos + p2.xpos;
	point->ypos=p1.ypos + p2.ypos;

	return *point;
}
int main(void){

	
	Point* point_1 = new Point;
	Point* point_2 = new Point;

	point_1->xpos=1;
	point_1->ypos=2;
	
	point_2->xpos=3;
	point_2->ypos=4;

	Point &ref = PntAdder(*point_1, *point_2);
	cout<<ref.xpos<<" "<<ref.ypos<<endl;


	delete point_1;
	delete point_2;
	delete &ref; // ref's address 

	return 0;


}
