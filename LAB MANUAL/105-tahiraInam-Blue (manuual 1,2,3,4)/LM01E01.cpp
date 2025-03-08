#include <iostream>
#include <string>
using namespace std;

struct Employee {
	//employee attributes
	int emp_num, dep_num;
	string name;
	float salary;
	Employee *next;
};
// class for handling employee functionality
class Emp_linked_list {
	private:
	   Employee *head;
	   Employee *tail;
	   int count;
    public:
    	//constructor
    	Emp_linked_list() {
    		head = NULL;
    		tail = NULL;
    		count = 0;
		}
	// Function for insertion
	void insert() {
		cout<<"\n\t-----------INSERT-----------\n";
		Employee * temp = new Employee;
		cout<<"\n\tEnter Employee Number: ";
		cin>>temp->emp_num;
		cout<<"\tEnter Employee Name: ";
		cin.ignore();
	    getline(cin, temp->name);
	    cout<<"\tEnter Salary: ";
	    cin>>temp->salary;
	    cout<<"\tEnter Demaprtment Number: ";
	    cin>>temp->dep_num;
	    
	    temp->next = NULL;
	    
	    if (head == NULL){
	    	head = temp;
	    	tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
		count++;
	}
	// Function for display
	void display() {
		cout<<"\n\t-----------DISPLAY-----------\n";
		Employee *temp = head;
		while (temp != NULL) {
			cout<<"\n\n\tEmployee Number: "<<temp->emp_num;
		    cout<<"\n\tEmployee Name: "<<temp->name;
	        cout<<"\n\tSalary: "<<temp->salary;
	        cout<<"\n\tDemaprtment Number: "<<temp->dep_num;
			temp = temp->next;
		}
		cout<<"\n\n\tTotal Employees: "<<count<<"\n";
	}
	// Function for updation 
	void update() {
		cout<<"\n\t-----------UPDATE-----------\n";
		int f=0, num;
		Employee *temp = head;
		cout<<"\n\tEnter Employee/Department Number to Update: ";
		cin>>num;
		while (temp != NULL){
			if (temp->dep_num == num || temp->emp_num == num){
				f = 1;
				break;
			}
			temp = temp->next;
		}
		if (f==1) {
			int choice;
			do {
				cout<<"\n\t----UPDATE----";
				cout<<"\n\t0. Exit";
				cout<<"\n\t1. Update Employee Number";
				cout<<"\n\t2. Update Employee Name";
				cout<<"\n\t3. Update Salary";
				cout<<"\n\t4. Update Department";
				cout<<"\n\t--------------\n";
				cout<<"\n\tEnter Choice: ";
				cin>>choice;
				switch (choice){
					case 0:
						cout<<"\n\tExiting...\n";
						break;
					case 1:
						cout<<"\n\tUpdate Employee Number: ";
			            cin>>temp->emp_num;
			            cout<<"\n\tEmployee Number Updated successfuly\n";
			            break;
					case 2:
						cout<<"\n\tUpdate Employee Name: ";
			            cin.ignore();
		                getline(cin, temp->name);
			            cout<<"\n\tName Updated successfuly\n";
			            break;
					case 3:
						cout<<"\n\tUpdate Salary: ";
			            cin>>temp->salary;
			            cout<<"\n\tSalary Updated successfuly\n";
			            break;
					case 4:
						cout<<"\n\tUpdate Department Number: ";
			            cin>>temp->dep_num;
			            cout<<"\n\tDepartment Number Updated successfuly\n";
			            break;
			        default:
			        	cout<<"\n\tInvalid Choice. Try Again";
				}
			} while (choice != 0);
		}
		else {
			cout<<"\n\tRECORD NOT FOUND\n";
		}
	}
	
	// Function for searching
	void search() {
		cout<<"\n\t-----------SEARCH-----------\n";
		int f=0, num;
		Employee *temp = head;
		cout<<"\n\tEnter Employee/Department Number to search: ";
		cin>>num;
		while (temp != NULL){
			if (temp->dep_num == num || temp->emp_num == num){
				f = 1;
				break;
			}
			temp = temp->next;
		}
		if (f == 1) {
			cout<<"\n\tRECORD FOUND\n";
			cout<<"\n\tEmployee Number: "<<temp->emp_num;
		    cout<<"\n\tEmployee Name: "<<temp->name;
	        cout<<"\n\tSalary: "<<temp->salary;
	        cout<<"\n\tDemaprtment Number: "<<temp->dep_num;
		}
		else {
			cout<<"\n\tRECORD NOT FOUND\n";
		}
	}
	// Function for deletion
	void Delete() {
		cout << "\n\t-----------DELETE-----------\n";
    int num;
    cout << "\n\tEnter Employee/Department Number to Delete: ";
    cin >> num;

    Employee *temp = head;
    Employee *prev = NULL;

    while (temp != NULL) {
        if (temp->emp_num == num || temp->dep_num == num) {
            if (prev == NULL) {
                // Deleting the head
                head = temp->next;
            } else {
                // Deleting a non-head node
                prev->next = temp->next;
            }

            //deleting the tail
            if (temp == tail) {
                tail = prev; 
            }

            delete temp; 
            count--; 
            cout << "\n\tRecord Deleted Successfully\n";
            return;
        }
        
        prev = temp; 
        temp = temp->next; 
    }

    cout << "\n\tRECORD NOT FOUND\n";
}
};

int main()
{
	Emp_linked_list ell;
	
	while (true)
	{
		cout<<"\n\n\t----MENU----";
		cout<<"\n\t1. Insert";
		cout<<"\n\t2. Display";
		cout<<"\n\t3. Update";
		cout<<"\n\t4. Search";
		cout<<"\n\t5. Delete";
		cout<<"\n\t6. Exit";
		cout<<"\n\t-------------\n";
		int choice;
		cout<<"\n\tEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				ell.insert();
				break;
			case 2:
				ell.display();
				break;
			case 3:
				ell.update();
				break;
			case 4:
				ell.search();
				break;
			case 5:
				ell.Delete();
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Choice. Please try again\n";
		}
	}
	
	return 0;
}
