#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
//For list insertion from user input
    void insert() {
        Node* temp = new Node;
        int x;
        cout << "Enter value to insert: ";
        cin >> x;
        temp->data = x;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
//display the list
    void display() {
        Node* tmp = head;

        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
//function to calculate the count separately.
    int getCount() {
        int count = 0;
        Node* tmp = head;
        while (tmp != NULL) {
            count++;
            tmp = tmp->next;
        }
        return count;
    }
/*function to elaborate use of function calling within function and creation of objects
		first we will find the mid position to inert the first half of the list into a separate list
		Then the rest of the original list will be inserted in a separate list

*/
    void split() {
        int totalCount = getCount();
        if (totalCount < 2) return;

        int mid = totalCount / 2;
        LinkedList list1;
        LinkedList list2;

        Node* current = head;
        Node* temp = NULL;

        for (int i = 0; i < mid; i++) {
            temp = current;
            list1.insertNode(current->data);
            current = current->next;
        }
        temp->next = NULL;

        while (current != NULL) {
            list2.insertNode(current->data);
            current = current->next;
        }
//displaying the two lists
        cout << "First List: ";
        list1.display();
        cout << "Second List: ";
        list2.display();
    }
//For insertion of exiting list and appropriately assigning head and tail 
    void insertNode(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

};

int main() {
    LinkedList L;
    L.insert();
    L.insert();
    L.insert();
    L.insert();
    cout << "Original List: ";
    L.display();

    L.split();

   

    return 0;
}
