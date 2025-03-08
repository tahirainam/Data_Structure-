#include <iostream>
using namespace std;

struct Node {
	int data;
	Node *next;
};

class SinglyLinkedList {
	private:
		Node *head, *tail;
	public:
		SinglyLinkedList(){
			head = NULL;
			tail = NULL;
		}
		void addNode() {
			Node *temp = new Node;
			cout<<"Enter Number: ";
			cin>>temp->data;
			temp->next = NULL;
			
			if (head==NULL) {
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				tail = temp;
			}
		}
		
		void Display() {
			Node *tmp;
			tmp = head;
			
			while (tmp != NULL) {
				cout<<tmp->data<<" ";
				tmp = tmp->next;
			}
		}
};

int main()
{
	SinglyLinkedList sll;
	sll.addNode();
	sll.addNode();
	sll.Display();
	return 0;
}
