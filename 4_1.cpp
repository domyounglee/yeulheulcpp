#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
	
public:
	int get_numOfApples() const
	{
		return numOfApples;
	}

	int get_myMoney() const
	{
		return myMoney;
	}

	bool set_numOfApples(int num){
		if(num<0){
			return false;
		}
		numOfApples-=num;
		return true;
	}

	bool set_myMoney(int money){
		if(money<0){
			return false;
		}
		myMoney+=money;
		return true;
	}


	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		numOfApples=num;
		myMoney=money;
	}
	int SaleApples(int money)  
	{
		if(money<0){
			return 0;
		}
		int num=money/APPLE_PRICE;
		numOfApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout<<"seller apple: "<<get_numOfApples()<<endl;
		cout<<"seller money: "<<get_myMoney()<<endl<<endl;
	}
};

class FruitBuyer
{
	int myMoney;		// private:
	int numOfApples;	// private:

public:

	int get_numOfApples() const
	{
		return numOfApples;
	}

	int get_myMoney() const
	{
		return myMoney;
	}

	bool set_numOfApples(int num){
		if(num<0){
			return false;
		}
		numOfApples+=num;
		return true;
	}

	bool set_myMoney(int money){
		if(money<0){
			return false;
		}
		myMoney-=money;
		return true;
	}


	void InitMembers(int money)
	{
		myMoney=money;
		numOfApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{

		set_numOfApples(seller.SaleApples(money));
		set_myMoney(money);
	}
	void ShowBuyResult() const
	{
		cout<<"buyer money: "<<get_myMoney()<<endl;
		cout<<"buyer apple: "<<get_numOfApples()<<endl<<endl;
	}
};

int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"buyer result"<<endl;
	buyer.ShowBuyResult();
	cout<<"seller result"<<endl;
	seller.ShowSalesResult();


	buyer.BuyApples(seller, -1000);	
	cout<<"seller result"<<endl;
	seller.ShowSalesResult();
	cout<<"buyer result"<<endl;
	buyer.ShowBuyResult();
	return 0;
}
