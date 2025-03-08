// doubly  linked list
//BOOK STRUCTURE
// with LIBRARY CLASS
#include <iostream>
#include <string>
using namespace std;

struct Book {
	string author, title;
	int publicationYear, isbn;
	Book *next;
	Book *pre;
};

class Library {
	private:
		Book *head;
		Book *tail;
		int count;
	public:
		// CONSTRUCTOR
		Library() {
			head = NULL;
			tail = NULL;
			count = 0;
		}
		//INSERTION
		void insertBook() {
			Book *temp = new Book;
			
			cout<<"\n\tEnter Book ISBN: ";
			cin>>temp->isbn;
			cout<<"\tEnter Book Title: ";
			cin.ignore(); 
            getline(cin, temp->title);
			cout<<"\tEnter Author Name: ";
			cin.ignore(); 
            getline(cin, temp->author);
			cout<<"\tEnter Publication Year: ";
			cin>>temp->publicationYear;
			
			temp->next = NULL;
			temp->pre = NULL;
			
			if (head == NULL){
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				temp->pre = tail;
				tail = temp;
			}
			// TOTAL BOOKS/NODES
			count++;
		}
		//DISPLAYING
		void Display(){
			Book *temp = head;
			
			if (head == NULL) {
               cout << "\n\tNo books available.\n";
               return;
            }
			
			cout<<"\n\t-----------------------------------\n";
			while (temp != NULL){
				cout<<"\n\tBook ISBN: "<<temp->isbn;
				cout<<"\n\tBook Title: "<<temp->title;
				cout<<"\n\tAuthor Name: "<<temp->author;
				cout<<"\n\tPublication Year: "<<temp->publicationYear<<endl;;
				temp = temp->next;
			}
			cout<<"\n\n\tTOTAL BOOKS: "<<count<<endl;
		    cout<<"\n\t-----------------------------------\n";

		}
		//SEARCHING FOR RECOMMENDATION
		void searchRecommendation(){
			int num, f = 0;
			cout<<"\n\tEnter Book ISBN to search: ";
			cin>>num;
			Book *temp = head;
			while (temp != NULL){
				if (temp->isbn == num ) {
					f = 1;
					temp = temp->next;
					// To search the next book for recommendation
                    if (temp == NULL) {
                       cout << "\n\tNo More BOOK Recommendations\n";
                    } else {
                    // New Book Recommendation
                        cout << "\n\tNew Book Recommendation: \n";
                        cout << "\n\tBook ISBN: " << temp->isbn;
                        cout << "\n\tBook Title: " << temp->title;
                        cout << "\n\tAuthor Name: " << temp->author;
                        cout << "\n\tPublication Year: " << temp->publicationYear;
                    }
                    break;
				}
				temp = temp->next;
			}
			if (f == 0) {
               cout << "\n\tBook Not Found\n";
            }
		}
		//SIMPLE SEARCH
		//SEARCHING
		void search(){
			int num, f = 0;
			cout<<"\n\tEnter Book ISBN to search: ";
			cin>>num;
			Book *temp = head;
			while (temp != NULL){
				if (temp->isbn == num ) {
					f = 1;
					
					break;
				}
				temp = temp->next;
			}
			if (f == 1){
				cout<<"\n\tBook Found\n";
				cout<<"\n\tBook ISBN: "<<temp->isbn;
				cout<<"\n\tBook Title: "<<temp->title;
				cout<<"\n\tAuthor Name: "<<temp->author;
				cout<<"\n\tPublication Year: "<<temp->publicationYear;
			}
			else {
				cout<<"\n\tBook Not Found";
			}
		}
};

int main(){
	Library l;
	while (true) {
		cout<<"\n\n\t----MENU----\n";
		cout<<"\n\t1. INSERT A BOOK";
		cout<<"\n\t2. DISPLAY";
		cout<<"\n\t3. SEARCH";
		cout<<"\n\t4. SEARCH RECOMMENDATION";
		cout<<"\n\t5. Exit";
		int choice;
		cout<<"\n\n\tEnter Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				l.insertBook();
				break;
			case 2:
				l.Display();
				break;
			case 3:
				l.search();
				break;
			case 4:
				l.searchRecommendation();
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}
