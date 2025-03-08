#include <iostream>
using namespace std;

struct Node {
	char data;
	Node *ptr;
};

class Dstack {
	private:
		Node *top;
	public:
		Dstack() {
			top = NULL;
		}
		//INSERTION
		void push() {
			Node *temp = new Node;
			cout<<"\n\tDATA? ";
			cin>>temp->data;
			temp->ptr = NULL;
			if(top == NULL) {
				top = temp;
			} else {
				temp->ptr = top;
				top = temp;
			}
		}
		//DELETION
		void pop() {
			if(top == NULL) {
				cout<<"\n\tunderflowed\n";
			} else {
				char num = top->data;
				Node *temp = top;
				temp = temp->ptr;
				delete temp;
			}
		}
		//DISPLAY
		void display() {
			Node *temp = top;
			cout<<"\n";
			while (temp != NULL) {
				cout<<"\t"<<temp->data;
				temp = temp->ptr;
			}
			cout<<"\n";
		}
		//CHANCKING BALANCED EXPRESSION
		void balancedExpression (string expression) {
			Dstack d;
			char i, c;
			while (i < expression.length()) {
				c = expression[i];
				if (c == '(') {
					d.push();
				} else if (c == ')') {
					if (d.top == NULL) {
						cout<<"\n\tINVALID\n";
					}
				} else {
					d.pop();
				}
				}
			d.top == NULL;
		}
};

int main()
{
	Dstack ds;
	while (true){
		cout<<"\n\n\tMENU\n";
		cout<<"\n\t1. PUSH\n";
		cout<<"\t2. POP\n";
		cout<<"\t3. DISPLAY\n";
		cout<<"\t4. CHANCKING BALANCED EXPRESSION\n";
		cout<<"\t5. EXIT";
		int choice;
		cout<<"\n\tChoice? ";
		cin>>choice;
		switch(choice){
			case 1:
				ds.push();
				break;
			case 2:
				ds.pop();
				break;
			case 3:
				ds.display();
				break;
			case 4:
				ds.balancedExpression("(98*0)");
				break;	
			case 5:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Input";
		}
	}
	
	return 0;
}
