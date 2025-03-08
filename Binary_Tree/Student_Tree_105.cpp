#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    float marks;
    Node *left;
    Node *right;
};

class StudentTree {
private:
    Node *root;

public:
    StudentTree() {
        root = NULL;
    }

    Node *insert(int id, string name, float marks, Node *temp) {
        if (temp == NULL) {
            temp = new Node;
            temp->id = id;
            temp->name = name;
            temp->marks = marks;
            temp->left = NULL;
            temp->right = NULL;
            if (root == NULL) {
                root = temp;
            }
        } else if (id < temp->id) {
            temp->left = insert(id, name, marks, temp->left);
        } else {
            temp->right = insert(id, name, marks, temp->right);
        }
        return temp;
    }

    void preOrder(Node *temp) {
        if (temp != NULL) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
            preOrder(temp->left);
            preOrder(temp->right);
        }
    }

    void postOrder(Node *temp) {
        if (temp != NULL) {
            postOrder(temp->left);
            postOrder(temp->right);
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
        }
    }

    void inOrder(Node *temp) {
        if (temp != NULL) {
            inOrder(temp->left);
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Marks: " << temp->marks << "\n";
            inOrder(temp->right);
        }
    }

    Node *search(int id, Node *temp) {
        if (temp == NULL || temp->id == id) {
            return temp;
        } else if (id < temp->id) {
            return search(id, temp->left);
        } else {
            return search(id, temp->right);
        }
    }

    Node *getRoot() {
        return root;
    }
};

int main() {
    StudentTree st;
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Insert Student\n";
        cout << "2. Display Pre Order\n";
        cout << "3. Display Post Order\n";
        cout << "4. Display In Order\n";
        cout << "5. Search Student by ID\n";
        cout << "6. Exit\n";
        int choice;
        cout << "Choice? ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id;
            string name;
            float marks;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Marks: ";
            cin >> marks;
            st.insert(id, name, marks, st.getRoot());
            break;
        }
        case 2:
            cout << "Pre Order Display:\n";
            st.preOrder(st.getRoot());
            break;
        case 3:
            cout << "Post Order Display:\n";
            st.postOrder(st.getRoot());
            break;
        case 4:
            cout << "In Order Display:\n";
            st.inOrder(st.getRoot());
            break;
        case 5: {
            int id;
            cout << "Enter Student ID to Search: ";
            cin >> id;
            Node *result = st.search(id, st.getRoot());
            if (result != NULL) {
                cout << "Student Found! ID: " << result->id << ", Name: " << result->name << ", Marks: " << result->marks << "\n";
            } else {
                cout << "Student with ID " << id << " not found.\n";
            }
            break;
        }
        case 6:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
