#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos){
		switch(pos){
			case CLERK:
				cout<<"sawon"<<endl;
				break;
			case SENIOR:
				cout<<"juim"<<endl;
				break;
			case ASSIST:
				cout<<"deri"<<endl;
				break;
			case MANAGER:
				cout<<"guajang"<<endl;
				break;

		}
	}
};
class NameCard
{
	char* name ;
	char* company ;
	char* phone ;
	int position;

	public:
		NameCard(char* n, char* c, char* p, int pos):position(pos){
			name= new char[strlen(n)+1];
			company = new char[strlen(c)+1];
			phone = new char[strlen(p)+1];
			strcpy(name, n);
			strcpy(company, c);
			strcpy(phone, p);

		}

		void ShowNameCardInfo(){
			cout<<name<<company<<phone<<endl;
			COMP_POS::ShowPositionInfo(position);
		}
		~NameCard(){
			delete []name;
			delete []company;
			delete []phone;
		}

};

int main(void){
	NameCard manClerk("LEE", "ABCENG", "1020310", COMP_POS::CLERK);
	manClerk.ShowNameCardInfo();
	return 0;
}