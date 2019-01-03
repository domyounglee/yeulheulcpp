#include<iostream>
#include<cstring>

using namespace std;

class Book
{
	private:
		char* title;
		char* isbn;
		int price;
	public:
		Book(char* name, char* isbn,int price):price(price){
			this->title= new char[strlen(name)+1];
			strcpy(this->title,name);
			this->isbn= new char[strlen(isbn)+1];
			strcpy(this->isbn,isbn);
		}
		void ShowBookInfo(){
			cout<<this->title<<endl;
			cout<<this->isbn<<endl;
			cout<<this->price<<endl<<endl;
		}

};

class EBook:public Book
{
	private:
		char* DRMKey;
	public:
		EBook(char* name, char* isbn,int price, char* key):Book(name, isbn,price){
			DRMKey= new char[strlen(name)+1];
			strcpy(DRMKey,key);
		}
		void ShowEBookInfo(){
			ShowBookInfo();
			cout<<this->DRMKey<<endl;

		}
};

int main(void){
	Book book("좋은 C++", "555-12345-890-0",20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 C++ ebook","555-12345-890-0",10000,"asdf");
	ebook.ShowEBookInfo();
	return 0;
}