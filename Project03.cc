#include<iostream>
#include<cstring>

#define MAX 100
using namespace std;



class Account{
	int ID;
	char* name;
	int balance;

	public:
		Account(int _ID, char* _name, int _balance)
			:ID(_ID),balance(_balance){
			this->name = new char(strlen(_name)+1);
			strcpy(this->name ,_name);

		}
		Account(const Account &account)
			:ID(account.ID),balance(account.balance){
			this->name = new char(strlen(account.name)+1);
			strcpy(this->name ,account.name);

		}

		int getID() const{
			return this->ID;
		}
		int getBalance() const{
			return this->balance;
		}

		void deposit(int money){
			this->balance+=money;

		}
		void withdraw(int money){
			this->balance-=money;

		}

		void showmyAccount() const{
			cout<<"my id:"<<this->ID<<endl;
			cout<<"my name:"<<this->name<<endl;
			cout<<"my id:"<<this->balance<<endl;

		}

		~Account(){
			delete []name;
		}
};


Account* acc[MAX];
int curr_pos=0;



void MakeAccount(void){
	if(curr_pos < MAX){
		char* name= new char[20];
		int ID ;
		int balance;
		
		cout<<"이름 : ";cin>>name;

		cout<<"아이디 : ";cin>>ID;
		cout<<"잔액 : ";cin>>balance;
	
		acc[curr_pos++]=new Account(ID, name, balance);

		
	}
	else{
		cout<<"Account array is full"<<endl;
	}
	return ;
}

void Deposit(void){
	int ID,amount;
	cout<<"아이디 : ";cin>>ID;
	cout<<"금액 : ";cin>>amount;

	for(int i=0;i<curr_pos;i++){
		if(acc[i]->getID() == ID){
			acc[i]->deposit(amount);
			cout<<"current balance"<<acc[i]->getBalance()<<endl;
			return ;
		}
	}
	cout<<"ID doesn't exist"<<endl;
	return ;
}

void Withdraw(void){
	int ID,amount;
	cout<<"아이디 : ";cin>>ID;
	cout<<"금액 : ";cin>>amount;
	

	for(int i=0;i<curr_pos;i++){
		if(acc[i]->getID() == ID){
			if(acc[i]->getBalance()-amount>=0){
				acc[i]->withdraw(amount);
				cout<<"current balance"<<acc[i]->getBalance()<<endl;

			}
			else{
				cout<<"balane is not enough"<<endl;
			}
			return ;
		}
	}
	cout<<"ID doesn't exist"<<endl;
	return ;
}

void showAllAcount(void){
	for(int i=0;i<curr_pos;i++){
		cout<<"================="<<endl;
		acc[i]->showmyAccount();


	}

	return ;
	
}


int main(void){
	int choice;
	while(1){
		cout<<"====Menu===="<<endl;
		cout<<"1. 계좌계설"<<endl;
		cout<<"2. 입금"<<endl;
		cout<<"3. 출금"<<endl;
		cout<<"4. 계좌정보 전체 출력"<<endl;
		cout<<"5. 프로그램 종료"<<endl;
		cout<<"선택";
		cin>>choice;
		

		switch(choice){
			case 1:
				MakeAccount();
				break;
			case 2:
				Deposit();
				break;
			case 3:
				Withdraw();
				break;
			case 4:
				showAllAcount();
				break;
			case 5:
				return 0;
			default:
				cout<<"Wrong Selection"<<endl;
				break;
		}

	}

	for(int i =0; i<curr_pos ;i++){
		cout<<"delete"<<i<< endl;
		delete acc[i];
	}
	return 0;
}

