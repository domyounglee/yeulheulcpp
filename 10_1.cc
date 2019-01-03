#include <iostream>
using namespace std;

class Point{
	int xpos,ypos;
	public:
		Point(int x=0, int y=0):xpos(x),ypos(y){

		}
		void ShowPosition() const{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
		friend ostream& operator<<(ostream&, const Point&);
		friend istream& operator>>(istream&,  Point&);
};

ostream& operator<<(ostream& os, const Point& pos){
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}
istream& operator>>(istream& is,  Point& pos){
	is>>pos.xpos>>pos.ypos;
	return is;
}

int main(void){
	Point pos1(1,3);
	cout<<pos1;
	Point pos2(101,303);
	cout<<pos2;
	Point pos3;
	cin>>pos3;
	cout<<pos3;
	return 0;
}