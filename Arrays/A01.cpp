//ARRAY OPERATIONS
#include <iostream>
using namespace std;

//CLASS
class Array {
	private:  
	   int arr[10];
	   int size = 10;
	   int index;
	public:
		//CONSTRUCTOR
		Array() {
			index = 0;
		}
		//INSERTION
		void insert() {
			if (index >= size) {
				cout<<"\n\tNO MORE SPACE\n";
			} else {
				cout<<"\n\tEnter Data: ";
				cin>>arr[index];
				index++;
			}
		}
		//DISPLAY
		void display() {
			cout<<"\n";
			for (int i = 0; i < index; i++) {
				cout<<"\t"<<arr[i];
			}
			cout<<"\n";
		}
		//SEARCHING IN AN ARRAY
		void search() {
			int f = 0, num, ind;
			cout<<"\n\tEnter number to search: ";
			cin>>num;
			for (int i = 0; i < index; i++) {
				if (arr[i] == num) {
					f = 1;
					ind = i;
					break;
				}
			}
			if (f == 1) {
				cout<<"\n\tFOUND At INDEX "<<ind<<endl;
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
		//UPDATION IN AN ARRAY
		void update() {
			int f = 0, oldV, newV;
			cout<<"\n\tEnter number to update: ";
			cin>>oldV;
			cout<<"\n\tEnter new number: ";
			cin>>newV;
			for (int i = 0; i < index; i++) {
				if (arr[i] == oldV) {
					arr[i] = newV;
					f = 1;
					break;
				}
			}
			if (f == 1) {
				cout<<"\n\tUPDATED SUCCESSFULLY"<<endl;
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
		//DELETION IN ARRAY
		void Delete() {
			int num, ind, f = 0;
			cout<<"\n\tEnter number to delete: ";
			cin>>num;
			for (int i = 0; i < index; i++) {
				if (arr[i] == num) {
					ind = i;
					f = 1;
					break;
				}
			}
			for (int j = ind; j < index; j++) {
				arr[j] = arr[j+1];
			}
			if (f == 1) {
			    index--;
				cout<<"\n\tDELETED SUCCESSFULLY\n";
			} else {
				cout<<"\n\tNOT FOUND\n";
			}
		}
};

int main() {
	Array A;
	while (true) {
		cout<<"\n\tMENU\n";
		cout<<"\n\t1. INSERT";
		cout<<"\n\t2. DISPLAY";
		cout<<"\n\t3. SEARCH";
		cout<<"\n\t4. UPDATE";
		cout<<"\n\t5. DELETE";
		cout<<"\n\t6. EXIT\n";
		int choice;
		cout<<"\n\tEnter choice: ";
		cin>>choice;
		switch (choice) {
			case 1:
				A.insert();
				break;
			case 2:
				A.display();
				break;
			case 3:
				A.search();
				break;
			case 4:
				A.update();
				break;
			case 5:
				A.Delete();
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}