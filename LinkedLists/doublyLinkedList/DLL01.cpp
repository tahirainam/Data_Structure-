//DOUBLY LINKED LIST
#include <iostream>
using namespace std;

//STRUCTURE
struct Node {
	int data;
	Node *next;
	Node *pre;
};

//CLASS
class Dlist {
	private:
		Node *head;
		Node *tail;
	public:
		//CONSTRUCTOR
		Dlist() {
			head = NULL;
			tail = NULL;
		}
		//INSERTION IN DOUBLY LINKED LIST
		void insert() {
			Node *temp = new Node;
			cout<<"\n\tEnter Data: ";
			cin>>temp->data;
			temp->pre = NULL;
			temp->next = NULL;
			if(head == NULL) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				temp->pre = tail;
				tail = temp;
			}
		}
		//DISPLAYING DOUBLY LINKED LIST
		void display() {
			Node *temp = head;
			cout<<"\n";
			while(temp != NULL) {
				cout<<"\t"<<temp->data;
				temp = temp->next;
			}
			cout<<"\n";
		}
		//BACKWARD DISPLAYING DOUBLY LINKED LIST
		void Bdisplay() {
			Node *temp = tail;
			cout<<"\n";
			while(temp != NULL) {
				cout<<"\t"<<temp->data;
				temp = temp->pre;
			}
			cout<<"\n";
		}
		//BINARY SEARCH
		void Bsearch() {
			Node *temp = head;
			Node *temp2 = tail;
			int num, f = 0;
			cout<<"\n\tEnter number to search: ";
			cin>>num;
			while (temp != NULL){
				if (temp->data == num || temp2->data == num){
					f = 1;
					break;
				}
				temp = temp->next;
				temp2 = temp2->pre;
			}
			if (f == 1) {
				cout<<"\n\tFOUND\n";
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
		//UPDATION IN DOUBLY LINKED LIST
		void update() {
			Node *temp = head;
			int oldV, newV, f = 0;
			cout<<"\n\tEnter number to update: ";
			cin>>oldV;
			cout<<"\n\tEnter new number: ";
			cin>>newV;
			while (temp != NULL){
				if (temp->data == oldV){
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
		//DELETION IN DOUBLY LINKED LIST
		void Delete() {
			Node *temp = head;
			Node *prev = NULL;
			int num, f = 0;
			cout<<"\n\tEnter number to delete: ";
			cin>>num;
			while (temp != NULL){
				if (temp->data == num){
					if (prev == NULL) {
						head = temp->next;
						temp->next->pre = NULL;
					} else if (temp == tail) {
						tail = prev;
						prev->next = NULL;
					} else {
						prev->next = temp->next;
						temp->next->pre = prev;
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
	Dlist D;
	//MENU
	while (true) {
		cout<<"\n\tMENU\n";
		cout<<"\n\t1. INSERT";
		cout<<"\n\t2. DISPLAY";
		cout<<"\n\t3. BACKWARD DISPLAY";
		cout<<"\n\t4. BINARY SEARCH";
		cout<<"\n\t5. UPDATE";
		cout<<"\n\t6. DELETE";
		cout<<"\n\t7. EXIT\n";
		int choice;
		cout<<"\n\tEnter choice: ";
		cin>>choice;
		switch (choice) {
			case 1:
				D.insert();
				break;
			case 2:
				D.display();
				break;
			case 3:
				D.Bdisplay();
				break;
			case 4:
				D.Bsearch();
				break;
			case 5:
				D.update();
				break;
			case 6:
				D.Delete();
				break;
			case 7:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}