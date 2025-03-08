#include <iostream>
#include <string>
using namespace std;

struct Student {
	//student attributes
	int RollNo;
	string name;
	float marks;
	
};
// class for handling Student functionality
class StudentArray {
	private:
	   Student arr[10];
       int size = 10;
       int index = 0;
       int counter = 0;
    public:
	// Function for insertion
	void insert() {
		cout<<"\n\t-----------INSERT-----------\n";
		if (index >= size) {
			cout<<"\n\tNo Space For More Data Entries\n";
		}
		else {
			cout<<"\n\tEnter student name: ";
			/*cin>>arr[index].name;*/
			cin.ignore();
			getline(cin, arr[index].name);
			cout<<"\tEnter student Roll No: ";
			cin>>arr[index].RollNo;
			cout<<"\tEnter student marks: ";
			cin>>arr[index].marks;
			index++;
			counter++;
		}
	}
	// Function for display
	void display() {
		cout<<"\n\t-----------DISPLAY-----------\n";
		for (int i=0; i<index; i++) {
			cout<<"\n\tTotal Students: "<<counter<<"\n";
			cout<<"\n\t----STUDENT #"<<i+1<<"----";
			cout<<"\n\t|Name: "<<arr[i].name;
			cout<<"\n\t|Roll No: "<<arr[i].RollNo;
			cout<<"\n\t|Marks: "<<arr[i].marks<<"\n";
		}
	}
	// Function for updation 
	void update() {
		cout<<"\n\t-----------UPDATE-----------\n";
		int f=0, rollno, ind;
		cout<<"\n\tWhich Record You Want to Update (Enter Roll No): ";
		cin>>rollno;
		for (int i=0; i<index; i++) {
			if (arr[i].RollNo == rollno) {
				f = 1;
				ind = i;
				break;
			}
		}
		if (f==1) {
			int choice;
			do {
				cout<<"\n\t----UPDATE----";
				cout<<"\n\t0. Exit";
				cout<<"\n\t1. Update Roll No";
				cout<<"\n\t2. Update Name";
				cout<<"\n\t3. Update Marks";
				cout<<"\n\t--------------\n";
				cout<<"\n\tEnter Choice: ";
				cin>>choice;
				switch (choice){
					case 0:
						cout<<"\n\tExiting...\n";
						break;
					case 1:
						cout<<"\n\tUpdate Student Roll No: ";
			            cin>>arr[ind].RollNo;
			            cout<<"\n\tRoll No Updated successfuly\n";
			            break;
					case 2:
						cout<<"\n\tUpdate Student Name: ";
			            cin.ignore();
		                getline(cin, arr[ind].name);
			            cout<<"\n\tName Updated successfuly\n";
			            break;
					case 3:
						cout<<"\n\tUpdate Student Marks: ";
			            cin>>arr[ind].marks;
			            cout<<"\n\tMarks Updated successfuly\n";
			            break;
			        default:
			        	cout<<"\n\tInvalid Choice. Try Again";
				}
			} while (choice != 0);
		}
		else {
			cout<<"\n\tRecord With "<<rollno<<" doesn\'t Exist";
		}
	}
	// Function for searching
	void search() {
		cout<<"\n\t-----------SEARCH-----------\n";
		int rollno, f=0, ind;
		cout<<"\n\tEnter Roll No to Search Student record: ";
		cin>>rollno;
		for (int i=0; i<index; i++) {
			if (arr[i].RollNo == rollno) {
				f = 1;
				ind = i;
			}
		}
		if (f == 1) {
			cout<<"\n\tRecord for Roll No "<<rollno<<" Found: \n";
			cout<<"\n\tRoll No: "<<arr[ind].RollNo;
			cout<<"\n\tName: "<<arr[ind].name;
			cout<<"\n\tMarks: "<<arr[ind].marks;
		}
		else {
			cout<<"\n\tRecord for Roll No "<<rollno<<" Not Found";
		}
	}
	// Function for deletion
	void Delete() {
		cout<<"\n\t-----------DELETE-----------\n";
		int rollno, ind, f = 0;
		cout<<"\n\tEnter Roll No to delete record: ";
		cin>>rollno;
		for (int i=0; i<index; i++) {
			if (arr[i].RollNo == rollno) {
				ind = i;
				f = 1;
				break;
			}
		}
		for (int j=ind; j<index; j++) {
			arr[j]= arr[j+1];
		}
		index--;
		if (f == 1) {
			cout<<"\n\tRecord Deleted Successfuly\n";
		}
		else {
			cout<<"\n\tRoll No Not Found";
		}
	}
};

int main()
{
	StudentArray s1;
	
	while (true)
	{
		cout<<"\n\n\t----MENU----";
		cout<<"\n\t1. Insert";
		cout<<"\n\t2. Display";
		cout<<"\n\t3. Update";
		cout<<"\n\t4. Search";
		cout<<"\n\t5. Delete";
		cout<<"\n\t6. Exit";
		cout<<"\n\t-------------\n";
		int choice;
		cout<<"\n\tEnter Your Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				s1.insert();
				break;
			case 2:
				s1.display();
				break;
			case 3:
				s1.update();
				break;
			case 4:
				s1.search();
				break;
			case 5:
				s1.Delete();
				break;
			case 6:
				return 0;
				break;
			default:
				cout<<"\n\tInvalid Choice. Please try again\n";
		}
	}
	return 0;
}
