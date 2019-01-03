#include<iostream>
#include<cstring>

using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(char* name,int age):age(age){
		this->name= new char[strlen(name)+1];
		strcpy(this->name,name);
	}
	void ShowMyFriendInfo(){
		cout<<"name: "<<name<<endl;
		cout<<"age:  "<<age<<endl;

	}
	~MyFriendInfo(){
		delete[] name;
		cout<<"bye1"<<endl;
	}
};

class MyFrienddetailInfo: public MyFriendInfo{
	private: 
		char* addr;
		char* phone;
	public:
		MyFrienddetailInfo(char*name, int age,char* addr,char* phone):MyFriendInfo(name,age){
			this->addr=new char[strlen(addr)+1];
			this->phone= new char[strlen(phone)+1];

			strcpy(this->addr,addr);
			strcpy(this->phone,phone);
		}
		void ShowMyFriendDetailInfo(){
			ShowMyFriendInfo();
			cout<<"address"<<this->addr<<endl;
			cout<<"phone"<<this->phone<<endl;
		}
		~MyFrienddetailInfo(){
			delete[] addr;
			delete[] phone;
			cout<<"bye2"<<endl;
		}
};


int main(void){
	MyFrienddetailInfo myfriend1("ShineSeungQ",30,"gangdong","010102039");
	myfriend1.ShowMyFriendDetailInfo();
	return 0;
}