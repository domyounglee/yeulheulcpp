#include <iostream>

void swap(int* a, int* b){
	int temp;
	temp= *a;
	*a=*b;
	*b=temp;
}

void swap(float* a, float* b){
	float temp;
	temp= *a;
	*a=*b;
	*b=temp;
}

int main(void){
	int num1=20, num2=30;
	swap(&num1, &num2);
	std::cout<<num1<<' '<<num2<<std::endl;
	float fnum1=20.1, fnum2=30.1;
	swap(&fnum1, &fnum2);
	std::cout<<fnum1<<' '<<fnum2<<std::endl;

	return 0;
}
