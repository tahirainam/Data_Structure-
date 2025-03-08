#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int emp_num, dep_num;
    string name;
    float salary;
    Employee *next;
};

class Emp_linked_list {
private:
    Employee *head;
    Employee *tail;
    int count;

public:
    Emp_linked_list() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    // Function for insertion
    void insert() {
        cout << "\n\t-----------INSERT-----------\n";
        Employee *temp = new Employee;
        cout << "\n\tEnter Employee Number: ";
        cin >> temp->emp_num;
        cout << "\tEnter Employee Name: ";
        cin.ignore();
        getline(cin, temp->name);
        cout << "\tEnter Salary: ";
        cin >> temp->salary;
        cout << "\tEnter Department Number: ";
        cin >> temp->dep_num;

        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    // Function for display
    void display() {
        cout << "\n\t-----------DISPLAY-----------\n";
        Employee *temp = head;
        while (temp != NULL) {
            cout << "\n\n\tEmployee Number: " << temp->emp_num;
            cout << "\n\tEmployee Name: " << temp->name;
            cout << "\n\tSalary: " << temp->salary;
            cout << "\n\tDepartment Number: " << temp->dep_num;
            temp = temp->next;
        }
        cout << "\n\n\tTotal Employees: " << count << "\n";
    }

    // Function to split the linked list into two new lists based on midpoint
    void split() {
        if (head == NULL) {
            cout << "\n\tList is empty, cannot split.\n";
            return;
        } 
        int mid = count / 2;
        Employee *temp = head;
        Emp_linked_list list1; 
        Emp_linked_list list2; 

        // Fill list1 up to the midpoint
        for (int i = 0; i < mid; i++) {
            Employee *newNode = new Employee;
            newNode->emp_num = temp->emp_num;
            newNode->name = temp->name;
            newNode->salary = temp->salary;
            newNode->dep_num = temp->dep_num;
            newNode->next = NULL;

            if (list1.head == NULL) {
                list1.head = newNode;
                list1.tail = newNode;
            } else {
                list1.tail->next = newNode;
                list1.tail = newNode;
            }
            list1.count++;
            temp = temp->next;
            
        }

        // Fill list2 with the remaining employees
        while (temp != NULL) {
            Employee *newNode = new Employee;
            newNode->emp_num = temp->emp_num;
            newNode->name = temp->name;
            newNode->salary = temp->salary;
            newNode->dep_num = temp->dep_num;
            newNode->next = NULL;

            if (list2.head == NULL) {
                list2.head = newNode;
                list2.tail = newNode;
            } else {
                list2.tail->next = newNode;
                list2.tail = newNode;
            }
            list2.count++;
            temp = temp->next; 
            
        }
        cout << "\n\t-----------LIST 1-----------\n";
        list1.display();
        cout << "\n\t-----------LIST 2-----------\n";
        list2.display();
    }
};

int main() {
    Emp_linked_list ell;

    while(true) {
		cout<<"\n\t----MENU----\n";
	    cout<<"\n\t1. Insert List";
	    cout<<"\n\t2. Split in 2 lists";
	    cout<<"\n\t3. Display";
	    cout<<"\n\t4. Exit";
	    int choice;
	    cout<<"\n\tEnter choice: ";
	    cin>>choice;
	    switch (choice)
	    {
	    	case 1:
	    		ell.insert();
	    		break;
	    	case 2:
	    		ell.split();
	    		break;
	    	case 3:
	    		ell.display();
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
