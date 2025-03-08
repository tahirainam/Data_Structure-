#include <iostream>
#include <string>
using namespace std;

struct Items {
	//items attributes
	string name;
	float price;
	int quantity;
	
};
// class for handling Items functionality
class ItemsArray {
	private:
	   Items arr[10];
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
			cout<<"\n\tEnter Item name: ";
			cin.ignore();
			getline(cin, arr[index].name);
			cout<<"\tEnter Price: ";
			cin>>arr[index].price;
			cout<<"\tEnter Quantity: ";
			cin>>arr[index].quantity;
			index++;
			counter++;
		}
	}
	// Function for display
	void display() {
		cout<<"\n\t-----------DISPLAY-----------\n";
		for (int i=0; i<index; i++) {
			cout<<"\n\tTotal Items: "<<counter<<"\n";
			cout<<"\n\t----ITEM #"<<i+1<<"----";
			cout<<"\n\t|Name: "<<arr[i].name;
			cout<<"\n\t|Price: "<<arr[i].price;
			cout<<"\n\t|Quantity: "<<arr[i].quantity<<"\n";
		}
	}
	// Function for updation 
	void update() {
		cout<<"\n\t-----------UPDATE-----------\n";
		int f=0, ind;
		string nm;
		cout<<"\n\tWhich Record You Want to Update (Enter Name): ";
		//cin>>rollno;
		cin.ignore();
		getline(cin,nm);
		for (int i=0; i<index; i++) {
			if (arr[i].name == nm) {
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
				cout<<"\n\t1. Update Name";
				cout<<"\n\t2. Update Price";
				cout<<"\n\t3. Update Quantity";
				cout<<"\n\t--------------\n";
				cout<<"\n\tEnter Choice: ";
				cin>>choice;
				switch (choice){
					case 0:
						cout<<"\n\tExiting...\n";
						break;
					case 1:
						cout<<"\n\tUpdate Name: ";
			            //cin>>arr[ind].name;
			            cin.ignore();
			            getline(cin, arr[index].name);
			            cout<<"\n\tName Updated successfuly\n";
			            break;
					case 2:
						cout<<"\n\tUpdate Price: ";
		                cin>>arr[ind].price;
			            cout<<"\n\tPrice Updated successfuly\n";
			            break;
					case 3:
						cout<<"\n\tUpdate Quantity: ";
			            cin>>arr[ind].quantity;
			            cout<<"\n\tQuantity Updated successfuly\n";
			            break;
			        default:
			        	cout<<"\n\tInvalid Choice. Try Again";
				}
			} while (choice != 0);
		}
		else {
			cout<<"\n\tItem "<<nm<<" doesn\'t Exist";
		}
	}
	// Function for searching
	void search() {
		cout<<"\n\t-----------SEARCH-----------\n";
		int f=0, ind;
		string nm;
		cout<<"\n\tEnter Name to search item : ";
		cin.ignore();
		getline(cin, nm);
		for (int i=0; i<index; i++) {
			if (arr[i].name == nm) {
				f = 1;
				ind = i;
			}
		}
		if (f == 1) {
			cout<<"\n\tItem "<<nm<<" Found: \n";
			cout<<"\n\tName: "<<arr[ind].name;
			cout<<"\n\tPrice: "<<arr[ind].price;
			cout<<"\n\tQuantity: "<<arr[ind].quantity;
		}
		else {
			cout<<"\n\tItem "<<nm<<" Not Found";
		}
	}
	// Function for deletion
	void Delete() {
		cout<<"\n\t-----------DELETE-----------\n";
		int ind, f = 0;
		string nm;
		cout<<"\n\tEnter Name to delete item: ";
		cin.ignore();
		getline(cin, nm);
		for (int i=0; i<index; i++) {
			if (arr[i].name == nm) {
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
			cout<<"\n\tItem Deleted Successfuly\n";
		}
		else {
			cout<<"\n\tItemn Not Found";
		}
	}
};

int main()
{
	ItemsArray i1;
	
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
				i1.insert();
				break;
			case 2:
				i1.display();
				break;
			case 3:
				i1.update();
				break;
			case 4:
				i1.search();
				break;
			case 5:
				i1.Delete();
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
