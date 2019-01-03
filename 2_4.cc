#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

int main(void){

	char *str1 = "ABC 123 ";
	char *str2 = "DEF 456 ";
	char str3[50];

	cout<<strlen(str1)<<endl;
	cout<<strlen(str2)<<endl;

	strcpy(str3, str1);
	strcat(str3,str2);

	cout<<str3<<endl;

	if(strcmp(str1, str2) == 0){
		cout<<"same str "<<endl;

	}
	else
		cout<< "not same str"<<endl;


	srand(time(NULL)); // random number seed with time(NULL) which is the whole second from 1970
	for(int i=0;i<5;i++){
		printf("Random number #%d: %d\n",i,rand()%100); //1~100
	}
	return 0;
}
