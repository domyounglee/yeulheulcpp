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

		Book(const Book& ref):price(ref.price){
			this->title= new char[strlen(ref.title)+1];
			strcpy(this->title,ref.title);
			this->isbn= new char[strlen(ref.isbn)+1];
			strcpy(this->isbn,ref.isbn);
		}

		Book& operator=(const Book& ref){



			delete []title;
			delete []isbn;

			this->price= ref.price;
			this->title= new char[strlen(ref.title)+1];
			strcpy(this->title,ref.title);
			this->isbn= new char[strlen(ref.isbn)+1];
			strcpy(this->isbn,ref.isbn);


			return *this;
		}
		void ShowBookInfo(){
			cout<<this->title<<endl;
			cout<<this->isbn<<endl;
			cout<<this->price<<endl<<endl;
		}
		~Book(){

			delete []title;
			delete []isbn;

		}
};

class EBook:public Book
{
	private:
		char* DRMKey;
	public:
		EBook(char* name, char* isbn,int price, char* key):Book(name, isbn,price){
			this->DRMKey= new char[strlen(name)+1];
			strcpy(this->DRMKey,key);
		}
		EBook(const EBook& ref):Book(ref){
			this->DRMKey= new char[strlen(ref.DRMKey)+1];
			strcpy(this->DRMKey,ref.DRMKey);			
		}
		EBook& operator=(const EBook& ref){
			Book::operator=(ref);
			delete[] DRMKey;
			this->DRMKey= new char[strlen(ref.DRMKey)+1];
			strcpy(this->DRMKey,ref.DRMKey);	


			return *this;
		}
		void ShowEBookInfo(){
			ShowBookInfo();
			cout<<this->DRMKey<<endl;

		}
};

int main(void){
	EBook ebook1("좋은 C++ ebook","555-12345-890-0",10000,"asdf");
	EBook ebook2=ebook1;//copy constructor

	ebook2.ShowEBookInfo();
	
	cout<<endl;

	EBook ebook3("dumy", "dumy", 0, "dumy"); //operator=
	ebook3=ebook2;
	ebook3.ShowEBookInfo();



	return 0;
}