#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* pre;
    Node* Next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insert() {
        int value;
        cout << "\n\tEnter value to insert: ";
        cin >> value;

        Node* newNode = new Node();
        newNode->Data = value;
        newNode->pre = NULL;
        newNode->Next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->Next != NULL) {
                temp = temp->Next;
            }
            temp->Next = newNode;
            newNode->pre = temp;
        }
    }

    void MoveToFront() {
        int value;
        cout << "\n\tEnter value to move to front: ";
        cin >> value;

        if (head == NULL) 
            return;

        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->Data != value) {
            previous = current;
            current = current->Next;
        }

        if (current == NULL || current == head)
            return;

        if (previous != NULL) {
            previous->Next = current->Next;
        }
        if (current->Next != NULL) {
            current->Next->pre = previous;
        }

        current->Next = head;
        head->pre = current;
        current->pre = NULL;
        head = current;
    }

    void display() {
        if (head == NULL) {
            cout << "\n\tList is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != NULL) {
            cout <<"\t"<< current->Data << " ";
            current = current->Next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice;

    while (true) {
        cout << "\n\tMENU:\n";
        cout << "\t1. Insert a new value\n";
        cout << "\t2. Move a value to the front\n";
        cout << "\t3. Display the list\n";
        cout << "\t4. Exit\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dll.insert();
                break;

            case 2:
                dll.MoveToFront();
                break;

            case 3:
                dll.display();
                break;

            case 4:
                cout << "Exiting program.\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
