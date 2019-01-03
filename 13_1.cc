#include <iostream>
using namespace std;

class Point
{
	private:
		int xpos, ypos;
	public:

		Point(int x=0, int y=0) : xpos(x), ypos(y){

		}
		void ShowPosition() const{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
};


template <typename T>  // right befor the T is used  not at the first where class Point is 
void SwapData(T& p, T& p2){
	
	T temp ;

	temp = p;
	p = p2;
	p2 = temp;


}

int main(void){
	Point point(1,2);
	Point point2(2,1);
	SwapData(point,point2);
	point.ShowPosition();
	point2.ShowPosition();
}