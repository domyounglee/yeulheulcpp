#include<iostream>

using namespace std;
int main(void){
	const int num=12;
	const int* pnum=&num;
	const int* (&refpnum)=pnum;

	cout<<*refpnum<<" "<<*pnum<<" "<<num;
}