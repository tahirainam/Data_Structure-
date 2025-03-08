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
		//SEARCHING
		void SearchNode(){
			int num, f = 0;
			Node *temp = head;
			cout<<"\n\tEnter Employee ID to search: ";
			cin>>num;
			
			while (temp != NULL) {
				if(temp->id == num){
					f = 1;
				}
				temp = temp->next;
			}
			if (f == 1){
				cout<<"\n\tFOUND\n";
			}
			else {
			cout<<"\n\tValue does not exist\n";	
			}
		}
		//UPDATION
		void updateNode(){
			//updating salary only
			int f=0;
			double slry, newslry;
			Node *temp = head;
			cout<<"\n\tEnter Current salary: ";
			cin>>slry;
			cout<<"\n\tEnter New salary: ";
			cin>>newslry;
			while (temp != NULL) {
				if(temp->salary == slry){
					f = 1;
					temp->salary = newslry;
				}
				temp = temp->next;
			}
			if (f == 1){
				cout<<"\n\tSalary Modified Successfully \n";
			} else {
			cout<<"\n\tdoes not exist\n";
			}
		}
		//DELETION AT START
		void DeleteNode(){
			int num, f = 0;
			Node *temp = head;
			cout<<"\n\tEnter Employee ID to delete: ";
			cin>>num;
			
			while (temp != NULL) {

			//as we are deleting at start only
			if (temp == head){
				head = head->next;
				delete temp;
				break;
	        }
			
			//deletion in the middle of the linked list
			else if(temp->next->id == num){
				Node *current = temp->next;
				temp->next = temp->next->next;
				delete current;
				break;
			}
				temp = temp->next;
			}
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
}};

int main()
{
	Emp_LinkedList A;
	
	while(true) {
		cout<<"\n\t----MENU----\n";
	    cout<<"\n\t1. Insert";
	    cout<<"\n\t2. Search By ID";
	    cout<<"\n\t3. Modify Salary";
	    cout<<"\n\t4. Delete At Start";
	    cout<<"\n\t5. Display";
	    cout<<"\n\t6. Exit";
	    int choice;
	    cout<<"\n\tEnter choice: ";
	    cin>>choice;
	    switch (choice)
	    {
	    	case 1:
	    		A.addNode();
	    		break;
	    	case 2:
	    		A.SearchNode();
	    		break;
	    	case 3:
	    		A.updateNode();
	    		break;
	    	case 4:
	    		A.DeleteNode();
	    		break;
	    	case 5:
	    		A.DislpayLinkedList();
	    		break;
	    	case 6:
	    		return 0;
	    		break;
	    	default:
	    		cout<<"\n\tInvalid Input\n";
		}
	}
	return 0;
}
