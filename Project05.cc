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


class AccountHandler{
	
	Account* acc[MAX];
	int curr_pos;

	public:
		AccountHandler(){
			this->curr_pos=0;
		}
		void MakeAccount(void){
			if(this->curr_pos < MAX){
				char* name= new char[20];
				int ID ;
				int balance;
				
				cout<<"이름 : ";cin>>name;

				cout<<"아이디 : ";cin>>ID;
				cout<<"잔액 : ";cin>>balance;
			
				this->acc[this->curr_pos++]=new Account(ID, name, balance);

				
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

			for(int i=0;i<this->curr_pos;i++){
				if(this->acc[i]->getID() == ID){
					this->acc[i]->deposit(amount);
					cout<<"current balance"<<this->acc[i]->getBalance()<<endl;
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
			

			for(int i=0;i<this->curr_pos;i++){
				if(this->acc[i]->getID() == ID){
					if(this->acc[i]->getBalance()-amount>=0){
						this->acc[i]->withdraw(amount);
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
			for(int i=0;i<this->curr_pos;i++){
				cout<<"================="<<endl;
				this->acc[i]->showmyAccount();


			}

			return ;
			
		}
		~AccountHandler(){
		for(int i =0; i<this->curr_pos;i++){
				cout<<"delete"<<i<< endl;
				delete acc[i];
			}
		}

};


int main(void){

	AccountHandler AH;

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
				AH.MakeAccount();
				break;
			case 2:
				AH.Deposit();
				break;
			case 3:
				AH.Withdraw();
				break;
			case 4:
				AH.showAllAcount();
				break;
			case 5:
				return 0;
			default:
				cout<<"Wrong Selection"<<endl;
				break;
		}

	}


	return 0;
}

