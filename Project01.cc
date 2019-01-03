#include<iostream>
#include<cstring>

#define MAX 100
using namespace std;

typedef struct {
	int ID;
	char name[20];
	int balance;
}Account;

Account acc_Arr[MAX];
int curr_pos=0;

void MakeAccount(void);

void Deposit(void);

void Withdraw(void);

void showAllAcount(void);

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


	return 0;
}

void MakeAccount(void){
	if(curr_pos < MAX){
		char name[20] ;
		int ID ;
		int balance;

		cout<<"이름 : ";cin>>name;
		cout<<"아이디 : ";cin>>ID;
		cout<<"잔액 : ";cin>>balance;
	
		
		acc_Arr[curr_pos].ID=ID;
		acc_Arr[curr_pos].balance=balance;
		strcpy(acc_Arr[curr_pos].name,name);
		curr_pos++;
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
		if(acc_Arr[i].ID == ID){
			acc_Arr[i].balance+=amount;
			cout<<"current balance"<<acc_Arr[i].balance<<endl;
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
		if(acc_Arr[i].ID == ID){
			if(acc_Arr[i].balance-amount>=0){
				acc_Arr[i].balance-=amount;
				cout<<"current balance"<<acc_Arr[i].balance<<endl;

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
		cout<<acc_Arr[i].name<<endl;
		cout<<acc_Arr[i].balance<<endl;
		cout<<acc_Arr[i].ID<<endl;

	}

	return ;
	
}


