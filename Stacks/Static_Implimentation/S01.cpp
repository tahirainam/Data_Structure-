#include <iostream>
#include <string>
using namespace std;

//CLASS
class StaticStack {
	private:
		int stack_arr[5];
		int top, index;
	public:
		//CONSTRUCTOR
		StaticStack() {
			top = -1;
			index = -1;
		}
		//INSERTION IN STATIC STACK
		void push() {
			if(top <= 4) {
				top++;
				cout<<"\n\tEnter value: ";
				cin>>stack_arr[top];
			}
			else {
				cout<<"\n\tOverflowed";
			}
			index++;
		}
		//DISPLAYING
		void dislay(){
			top = 0;
			int i = top;
			while (i <= index){
				cout<<"\n\t"<<stack_arr[i];
				i++;
			}
		}
		//DELETION IN STATIC STACK
		int pop() {
			if (top == -1){
				cout<<"\n\tUnderflowed";
			}
			else {
			   int num = stack_arr[top];
			   stack_arr[top] = 0;
			   top--;
			   return num;
	       	}
	    }
};

int main()
{
	StaticStack s;
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
				s.push();
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.dislay();
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
