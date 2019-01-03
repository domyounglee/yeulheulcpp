#include <iostream>
#include <cstring>
using namespace std;

class Person
{
	private:
		int age;
		char name[50];
	public:
		Person(int myage, char* myname) : age(myage)
		{
			strcpy(this->name,myname);
		}
		void WhatyourName() const{
			cout<<"Myname is "<<name<<endl;

		}
		void HowOldAreYou() const
		{
			cout<<"I'm "<<age<<" yerars old"<<endl;
		}

};

class UnivStudent : public Person
{
	private:
		char major[50];
	public: 
		UnivStudent(char* name,int age, char* major):Person(age,name){
			strcpy(this->major, major);

		}

		void WhoAreYou() const{
			WhatyourName();
			HowOldAreYou();
			cout<<"my major is"<<major<<endl;
		}
};

int main(void){
	UnivStudent ustd1("lee",22,"computer");
	ustd1.WhoAreYou();

	return 0;
}
