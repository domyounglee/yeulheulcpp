#include <iostream>
#include <cstring>

using namespace std;

class Rectangle{
	protected:
		int x;
		int y;
	public:
		Rectangle(int x,int y):x(x),y(y){

		}
		void ShowAreaInfo(){
			cout<<"area: "<<this->x*this->y<<endl;
		}
};
class Square: public Rectangle{
	public:
		Square(int x):Rectangle(x,x){
			
		}
		void ShowAreaInfo(){
			cout<<"squarex: "<<this->x*this->x<<endl;
		}

};
int main(void){
	Rectangle rec(4,3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}