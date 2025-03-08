#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};
class bTree{
	private:
		Node *root;
	public:
		bTree(){
			root = NULL;
		}
		//INSERTION
		Node *insert(int d, Node *temp){
			if(temp==NULL){
				temp = new Node;
				temp->data = d;
				temp->left = NULL;
				temp->right = NULL;
				if(root == NULL){
					root = temp;
				}
			}
			else if(temp->data > d){
				temp->left = insert(d, temp->left);
			}
			else {
				temp->right = insert(d, temp->right);
			}
			return temp;
		}
		//PRE ORDER DISPLAY
		void preOrder(Node *temp) {
        if (temp != NULL) {
            cout << "\tDATA: " << temp->data << "\n";
            preOrder(temp->left);
            preOrder(temp->right);
        }
    }
    //POST ORDER DISPLAY
    void postOrder(Node *temp) {
        if (temp != NULL) {
            postOrder(temp->left);
            postOrder(temp->right);
            cout << "\tDATA: " << temp->data << "\n";
        }
    }
    //IN ORDER DISPLAY
    void inOrder(Node *temp) {
        if (temp != NULL) {
            inOrder(temp->left);
            cout << "\tDATA: " << temp->data << "\n";            
			inOrder(temp->right);
        }
    }
    //SEARCH
    Node *search(int d, Node *temp) {
        if (temp == NULL || temp->data == d) {
            return temp;
        } else if (d < temp->data) {
            return search(d, temp->left);
        } else {
            return search(d, temp->right);
        }
    }
    //ROOT
    Node *getRoot() {
        return root;
    }
};
int main() {
    bTree bt;
    while (true) {
        cout << "\n\tMenu\n";
        cout << "\t1. Insert\n";
        cout << "\t2. Display Pre Order\n";
        cout << "\t3. Display Post Order\n";
        cout << "\t4. Display In Order\n";
        cout << "\t5. Search\n";
        cout << "\t6. Exit\n";
        int choice;
        cout << "\tChoice? ";
        cin >> choice;

        switch (choice) {
        case 1:
            int d;
            cout << "\tEnter Data: ";
            cin >> d;
            bt.insert(d, bt.getRoot());
            break;
        case 2:
            cout << "\tPre Order Display:\n";
            bt.preOrder(bt.getRoot());
            break;
        case 3:
            cout << "\tPost Order Display:\n";
            bt.postOrder(bt.getRoot());
            break;
        case 4:
            cout << "\tIn Order Display:\n";
            bt.inOrder(bt.getRoot());
            break;
        case 5: {
            int d;
            cout << "\tEnter Data to Search: ";
            cin >> d;
            Node *result = bt.search(d, bt.getRoot());
            if (result != NULL) {
                cout << "\tData Found!: " << result->data <<"\n";
            } else {
                cout << "\tData " << d << " not found.\n";
            }
            break;
        }
        case 6:
            cout << "\tExiting...\n";
            return 0;
        default:
            cout << "\tInvalid choice! Try again.\n";
        }
    }
}
