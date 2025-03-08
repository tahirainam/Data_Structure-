//Dynamic Queue (ticket booking system)
#include <iostream>
using namespace std;

struct Node {
	float price;
	string name;
	int id;
	Node *ptr;
};
class Dqueue{
	private:
		Node *front;
		Node *rear;
	public:
		Dqueue(){
			front = NULL;
			rear = NULL;
		}
		void enqueue(){
			Node *temp = new Node;
			cout<<"\n\tEnter Ticket ID: ";
			cin>>temp->id;
			cout<<"\tEnter Name:  ";
			cin>>temp->name;
			cout<<"\tEnter price: ";
			cin>>temp->price;
			temp->ptr = NULL;
			if (front == NULL){
				front = temp;
				rear = temp;
			} else {
				rear->ptr = temp;
				rear = temp;
			}
		}
		int dequeue(){
			Node *temp = front;
			if (temp == NULL){
				cout<<"\n\tEmpty"<<endl;
			} else {
				int num = temp->id;
				front = front->ptr;
				delete temp;
				return num;
			}
		}
		void display(){
			Node *temp = front;
			cout<<"\n\t-------------------\n";
			while (temp != NULL){
				cout<<"\n\tID: "<<temp->id<<endl;
				cout<<"\tName: "<<temp->name<<endl;
				cout<<"\tPrice: "<<temp->price<<endl;
				temp = temp->ptr;
			}
			cout<<"\n\t-------------------\n";
		}
};
int main() {
	Dqueue D;
	while(true) {
		cout << "\n\t----MENU----\n";
        cout << "\n\t1. Book Ticket";
        cout << "\n\t2. Cancel Ticket";
        cout << "\n\t3. View Tickets";
	    cout<<"\n\t4. Exit";
	    int choice;
	    cout<<"\n\tEnter choice: ";
	    cin>>choice;
	    switch (choice)
	    {
	    	case 1:
	    		D.enqueue();
	    		break;
	    	case 2:
	    		D.dequeue();
	    		break;
	    	case 3:
	    		D.display();
	    		break;
	    	case 4:
	    		return 0;
	    		break;
	    	default:
	    		cout<<"\n\tInvalid Input\n";
		}
	}
	return 0;
}
