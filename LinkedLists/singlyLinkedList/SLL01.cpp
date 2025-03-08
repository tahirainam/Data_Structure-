//SINGLY LINKED LIST
#include <iostream>
using namespace std;

//STRUCTURE
struct Node { 
	int data;
	Node *next;
};

//CLASS
class Slist {
	private:
		Node *head;
		Node *tail;
	public:
		//CONSTRUCTOR
		Slist() {
			head = NULL;
			tail = NULL;
		}
		//INSERTION IN SINGLY LINKED LIST
		void insert() {
			Node *temp = new Node;
			cout<<"\n\tEnter Data: ";
			cin>>temp->data;
			temp->next = NULL;
			if (head == NULL) {
				head = temp;
				tail = temp;
			} else {
				tail->next = temp;
				tail = temp;
			}
		}
		//DISPLAYING IN SINGLY LINKED LIST
		void display() {
			Node *temp = head;
			cout<<"\n";
			while (temp != NULL) {
				cout<<"\t"<<temp->data;
				temp = temp->next;
			}
			cout<<"\n";
		}
		//SEARCHING IN SINGLY LINKED LIST
		void search() {
			Node *temp = head;
			int num, f = 0;
			cout<<"\n\tEnter number to search: ";
			cin>>num;
			while (temp != NULL) {
				if (temp->data == num) {
					f = 1;
					break;
				}
				temp = temp->next;
			}
			if (f == 1) {
				cout<<"\n\tFOUND\n";
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
		//UPDATION IN SINGLY LINKED LIST
		void update() {
			Node *temp = head;
			int oldV, newV, f = 0;
			cout<<"\n\tEnter number to update: ";
			cin>>oldV;
			cout<<"\n\tEnter new number: ";
			cin>>newV;
			while (temp != NULL) {
				if (temp->data == oldV) {
					f = 1;
					temp->data = newV;
					break;
				}
				temp = temp->next;
			}
			if (f == 1) {
				cout<<"\n\tUPDATED SUCCESSFULLY\n";
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
		//DELETION IN SINGLY LINKED LIST
		void Delete() {
			Node *temp = head;
			Node *prev = NULL;
			int num;
			cout<<"\n\tEnter number to delete: ";
			cin>>num;
			while (temp != NULL) {
				if (temp->data == num) {
					if (prev == NULL) {
					  head = temp->next;
				   } else if (prev == tail) {
					  tail = prev;
				   } else {
					  prev->next = temp->next;
				   }
				   delete temp;
				   cout<<"\n\tDELETED SUCCESSFULLY\n";
				   return;
				}
				prev = temp;
				temp = temp->next;
			}
		}
};

//MAIN FUNCTION
int main() {
	Slist S;
	while (true) {
		cout<<"\n\tMENU\n";
		cout<<"\n\t1. INSERT";
		cout<<"\n\t2. DISPLAY";
		cout<<"\n\t3. SEARCH";
		cout<<"\n\t4. UPDATE";
		cout<<"\n\t5. DELETE";
		cout<<"\n\t6. EXIT\n";
		int choice;
		cout<<"\n\tEnter choice: ";
		cin>>choice;
		switch (choice) {
			case 1:
				S.insert();
				break;
			case 2:
				S.display();
				break;
			case 3:
				S.search();
				break;
			case 4:
				S.update();
				break;
			case 5:
				S.Delete();
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}