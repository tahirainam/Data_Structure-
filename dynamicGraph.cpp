#include <iostream>
using namespace std;

// STRUCTURE
struct Node {
    int data;
    Node* next;
};

// CLASS
class Slist {
private:
    Node* head;
    Node* tail;
public:
    // CONSTRUCTOR
    Slist() {
        head = NULL;
        tail = NULL;
    }

    // INSERTION IN SINGLY LINKED LIST
    void insert(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // DISPLAYING IN SINGLY LINKED LIST
    void display() {
        Node* temp = head;
        cout << "\n";
        while (temp != NULL) {
            cout << "\t" << temp->data;
            temp = temp->next;
        }
        cout << "\n";
    }
};

// MAIN FUNCTION
int main() {
    const int numNodes = 5; // Number of nodes in the graph
    Slist graph[numNodes]; // Array of Slist for the adjacency list representation

    while (true) {
        cout << "\n\tMENU\n";
        cout << "\n\t1. INSERT";
        cout << "\n\t2. DISPLAY";
        cout << "\n\t3. EXIT\n";
        int choice;
        cout << "\n\tEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < numNodes; i++) {
                    cout << "Enter number of nodes connected to Node " << i + 1 << ": ";
                    int n;
                    cin >> n;
                    for (int j = 0; j < n; j++) {
                        cout << "Enter data for connected Node: ";
                        int value;
                        cin >> value;
                        graph[i].insert(value);
                    }
                }
                break;
            }
            case 2: {
                for (int i = 0; i < numNodes; i++) {
                    cout << "\nConnections for Node " << i + 1 << ":";
                    graph[i].display();
                }
                break;
            }
            case 3:
                return 0;
            default:
                cout << "\n\tINVALID INPUT\n";
        }
    }
}
