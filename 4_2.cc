#include <iostream>
#include "Circle.h"
using namespace std;

class Ring{
	Circle inner;
	Circle outer;

	public:
		Ring(int x1, int y1, int r1, int x2, int y2, int r2)
			:inner(x1,y1,r1),outer(x2,y2,r2){
			
		
		}
		void ShowRingInfo() const{
			cout<<"inner"<<endl;
			inner.ShowCirInfo();
			cout<<"outer"<<endl;
			outer.ShowCirInfo();

		}
};
int main(void){
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}