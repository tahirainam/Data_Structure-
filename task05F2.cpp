#include <iostream>
using namespace std;

class Student {
	public:
		const int size = 10;
		int age[10] = {12, 13, 15, 46};
		int n = 4;
// FUNCTION FOR INSERTION
	void Insert() {
		int x;
		if (n>=size) {
			cout<<"\n\tNO SPACE FOR DATA\n";
		}
		
		cout<<"\n\tEnter data at end\n";
		cin>>x;
		
		age[n] = x;
		n++;
	}
//FUNCTION FOR UPDATION
    void Update() {
    	int position;
    	int value;
    	cout<<"\n\tEnter Position for updation: ";
    	cin>>position;
    	cout<<"\n\tEnter value: ";
    	cin>>value;
    	if(position > size-1 || position < 0) {
    		cout<<"\n\tInvalid Input";
		}
		age[position] = value;
	}
// FUNCTION FOR DISPLAY
	void Display() {
		cout<<"\n\tDisplaying Data\n";
		for (int i=0; i<size; i++) {
			cout<<"\n\t-------\n";
			cout<<"\t"<<age[i];
		}
	}
// FUNCTION FOR SEARCHING
    void Search() {
    	int valueToSearch;
    	cout<<"\n\tEnter value to search ";
    	cin>>valueToSearch;
    	int f = 0, ind;
    	for (int i = 0; i<n; i++) {
    		if (age[i]==valueToSearch) {
    			f = 1;
    			ind = i;
			}
		}
		if (f == 1)
		{
			cout<<"\n\tFound at Index "<<ind;
		}
		else 
		{
			cout<<"\n\tNot Found\n";
		}
	}
};

int main()
{
	Student s;
	while (true)
	{
		int choice;
		cout<<"\n\n\t----MENU----\n";
		cout<<"\n\t1. Insert";
		cout<<"\n\t2. Update";
		cout<<"\n\t3. Display";
		cout<<"\n\t4. Search";
		cout<<"\n\t5. Exit\n";
		cout<<"\n\tEnter your choice\n";
		cin>>choice;
		switch(choice){
			case 1:
				s.Insert();
				break;
			case 2:
				s.Update();
				break;
			case 3:
				s.Display();
				break;
			case 4:
				s.Search();
				break;
			case 5:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Input\n";
		}
	}
}
