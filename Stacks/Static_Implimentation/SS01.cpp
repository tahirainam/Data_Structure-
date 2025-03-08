//STATIC STACK
#include <iostream>
using namespace std;

//class
class Sstack {
	private:
		int Sarr[10];
		int size;
		int top;
	public:
		//constructor
		Sstack() {
			top = -1;
			size = 10;
		}
		//insertion
		void push() {
			if (top >= size) {
				cout<<"\n\tOVERFLOWED";
			} else {
				top++;
				cout<<"\n\tEnter data: ";
				cin>>Sarr[top];
			}
		}
		//DELETION
		int pop() {
			if (top == -1) {
				cout<<"\n\tUNDERFLOWED";
			} else {
				int num = Sarr[top];
				Sarr[top] = 0;
				top--;
			}
		}
		//DISPLAY
		void display() {
			cout<<"\n";
			for (int i=top; i>=0; i--) {
				cout<<"\t"<<Sarr[i];
			}
			cout<<"\n";
		}
};

//main function
int main()
{
	Sstack ss;
	while (true){
		cout<<"\n\n\tMENU\n";
		cout<<"\n\t1. PUSH\n";
		cout<<"\t2. POP\n";
		cout<<"\t3. DISPLAY\n";
		cout<<"\t4. EXIT";
		int choice;
		cout<<"\n\tChoice? ";
		cin>>choice;
		switch(choice){
			case 1:
				ss.push();
				break;
			case 2:
				ss.pop();
				break;
			case 3:
				ss.display();
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Input";
		}
	}
	
	return 0;
}
