#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class linked_recursion {
private:
    Node* head;
    Node* tail;

public:
    linked_recursion() {
        head = NULL;
        tail = NULL;
    }

    void addNode() {
        Node* temp = new Node;
        cout << "\n\tEnter Data: ";
        cin >> temp->data;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display(Node* temp) {
        if (temp == NULL) {
            return;
        } else {
            cout << temp->data << " ";
            display(temp->next); 
        }
    }
    
    void displayList() {
        display(head);  
        cout << endl;
    }
    
    void displayR(Node* temp) {
        if (temp == NULL) {
            return;
        } else {
        	displayR(temp->next); 
            cout << temp->data << " ";
        }
    }

    void rev_display() {
        displayR(head);  
        cout << endl;
    }
};

int main() {
    linked_recursion lr;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Node to Linked List" << endl;
        cout << "2. Display Linked List" << endl;
        cout << "3. Display Reversed Linked List" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lr.addNode();
            break;
        case 2:
            cout << "The linked list is: ";
            lr.displayList();
            break;
        case 3:
            cout << "The Reversed linked list is: ";
            lr.rev_display();
            break;
        case 4:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); 

    return 0;
}
