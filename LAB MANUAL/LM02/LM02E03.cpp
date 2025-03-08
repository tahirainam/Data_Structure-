//STATIC STACK
#include <iostream>
using namespace std;

//class
class Sstack {
	private:
		int Sarr[10];
		int Sarr2[10];
		int size;
		int top;
		int top2;
		int index;
	public:
		//constructor
		Sstack() {
			top = -1;
			top2 = -1;
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
		//SWAP
		void swap() {
			Sstack s2;
			if (top == -1) {
				cout<<"\n\tUNDERFLOWED";
			} else {
				while (top != -1) {
					top2++;
					Sarr2[top2] = Sarr[top];
					top--;
				}
			}
		}
		//DELETION
		void pop() {
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
		//DISPLAY SWAP
		void display2() {
			cout<<"\n";
			for (int i=top2; i>=0; i--) {
				cout<<"\t"<<Sarr2[i];
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
		cout<<"\t4. SWAP\n";
		cout<<"\t5. DISPLAY SWAPED\n";
		cout<<"\t6. EXIT";
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
				ss.swap();
				break;
			case 5:
				ss.display2();
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Input";
		}
	}
	
	return 0;
}
