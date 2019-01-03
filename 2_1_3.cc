#include<iostream>

using namespace std;

void SwapPointer(int*(&poi1), int*(&poi2)){

	int* temp=poi1; //pointer 변수 새로 하나 만듦 poi1과 별개 
	poi1 = poi2;
	poi2 = temp;

}


int main(void)
{
	int num1=5;
	int* ptr1=&num1;
	int num2=10;
	int* ptr2=&num2;

	cout<<*(ptr1)<<endl;
	cout<<*(ptr2)<<endl;


	SwapPointer(ptr1,ptr2);

	cout<<*(ptr1)<<endl;
	cout<<*(ptr2)<<endl;
}