// SINGLY LINKED LIST
#include <iostream>
#include <string>
using namespace std;

struct Inventory {
	string item_name;
	int quantity;
	Inventory *next;
};

class Items {
	private:
		Inventory *head;
		Inventory *tail;
		int count, Tquantity;
	public:
		// CONSTRUCTOR
		Items() {
			head = NULL;
			tail = NULL;
			count = 0;
			Tquantity = 0;
		}
		//INSERTION
		void insertItem() {
			Inventory *temp = new Inventory;
			cout<<"\n\tEnter Item Name: ";
			cin.ignore();
			getline(cin,temp->item_name);
			cout<<"\tEnter Item\'s Quantity: ";
			cin>>temp->quantity;
			// TOTAL QUANTITY
			Tquantity = Tquantity + temp->quantity;
			temp->next = NULL;
			if (head == NULL){
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
			// TOTAL INERTIONS/NODES
			count++;
		}
		//DISPLAYING
		void DisplayItems(){
			Inventory *temp = head;
			cout<<"\n\t-----------------------------------\n";
			while (temp != NULL){
				cout<<"\n\tItem Name: "<<temp->item_name;
				cout<<"\n\tItem\'s Quantity: "<<temp->quantity;
				temp = temp->next;
			}
			cout<<"\n\n\tTOTAL ITEMS: "<<count<<endl;
			cout<<"\n\tTOTAL QUANTITY: "<<Tquantity<<endl;
		    cout<<"\n\t-----------------------------------\n";

		}
};

int main(){
	Items i;
	while (true) {
		cout<<"\n\t----MENU----\n";
		cout<<"\n\t1. INSERT";
		cout<<"\n\t2. DISPLAY";
		cout<<"\n\t3. Exit";
		int choice;
		cout<<"\n\n\tEnter Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				i.insertItem();
				break;
			case 2:
				i.DisplayItems();
				break;
			case 3:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}
