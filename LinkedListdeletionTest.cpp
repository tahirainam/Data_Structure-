#include <iostream>
using namespace std;

struct Node {
	int id;
	string employee_name;
	double salary;
	Node *next;
};

class Emp_LinkedList {
	private:
		Node *head;
		Node *tail;
	public:
		Emp_LinkedList() {
			head = NULL;
			tail = NULL;
		}
		//INSERTION
		void addNode() {
			Node *temp = new Node;
			cout<<"\n\tEnter Employee ID: ";
			cin>>temp->id;
			cout<<"\n\tEnter Employee Name: ";
			cin>>temp->employee_name;
			cout<<"\n\tEnter Employee Salary: ";
			cin>>temp->salary;
			temp->next = NULL;
			
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else {
				tail->next = NULL;
				tail = temp;
			}
		}
		//DELETION AT START
		void DeleteNode(){
			int num, f = 0;
			Node *temp = head;
			cout<<"\n\tEnter Employee ID to delete: ";
			cin>>num;
			
			while (temp != NULL) {
				if(temp->id == num){
					f = 1;
					break;
				}
				temp = temp->next;
			}
			
			//as we are deleting at start only
			if (temp == head){
				head = head->next;
				delete temp;
			}
			/*
			//deletion in the middle of the linked list
			else if(temp->next->id == num){
				Node *current = temp->next;
				delete current;
				temp->next = temp->next->next;
			}
			*/
			if (f == 1){
				cout<<"\n\tDeleted Successfully ";
			}
			else {
			cout<<"\n\tdoes not exist\n";
			}
		}
		//DISPLAYING
		void DislpayLinkedList(){
			Node *temp = head;
		/*	if (temp == NULL){*/
				while (temp != NULL){
				cout<<"\n\tID: "<<temp->id;
				cout<<"\n\tNAME: "<<temp->employee_name;
				cout<<"\n\tSALARY: "<<temp->salary;
				temp = temp->next;
		/*	}
			}
			else {
				cout<<"\n\tEMPTY LINKED LIST\n";
			}
			*/	
		}
};

int main()
{
	Emp_LinkedList A;
	A.addNode();
	A.DeleteNode();
	//A.addNode();
	//A.DislpayLinkedList()
	    	
	
	return 0;
}
