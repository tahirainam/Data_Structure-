#include <iostream>
using namespace std;

class Student {
	public:
		const int size = 10;
		int marks[10] = {12, 13, 15, 46};
		int n = 4;
// FUNCTION FOR INSERTION AT END
	void InsertAtEnd() {
		int x;
		if (n>=size) {
			cout<<"\n\tNO SPACE FOR DATA\n";
		}
		
		cout<<"\n\tEnter data at end\n";
		cin>>x;
		
		marks[n] = x;
		n++;
	}
// FUNCTION FOR INSERTION AT START
    void InsertAtStart() {
    	int x;
		if (n>=size) {
			cout<<"\n\tNO SPACE FOR DATA\n";
		}
		
		cout<<"\n\tEnter data At Start\n";
		cin>>x;
		for (int i=n; i>=0; i--) {
			marks[i] = marks[i-1];
		}
		marks[0] = x;
		n++;
	}

// FUNCTION FOR DISPLAY
	void Display() {
		cout<<"\n\tDisplaying Data\n";
		for (int i=0; i<n; i++) {
			cout<<"\n\t-------\n";
			cout<<"\t"<<marks[i];
		}
	}
};

int main()
{
	Student s;
	while (true)
	{
		int choice;
		cout<<"\n\n\tMENU----\n";
		cout<<"\n\t1. Insert at End";
		cout<<"\n\t2. Insert at Start";
		cout<<"\n\t3. Display";
		cout<<"\n\t4. Exit\n";
		cout<<"\n\tEnter your choice\n";
		cin>>choice;
		switch(choice){
			case 1:
				s.InsertAtEnd();
				break;
			case 2:
				s.InsertAtStart();
				break;
			case 3:
				s.Display();
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Input\n";
		}
	}
}
