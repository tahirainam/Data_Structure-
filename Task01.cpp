#include <iostream>
using namespace std;
int n=4; 
const int size = 5;
int arr[5]= {45, 55, 89, 90};
    void display() {
		for (int i = 0; i<n; i++)
	    {
		cout<<arr[i]<<" ";	
	    }
    }
	void insert() {
		if (n>=size) {cout<<"\n\t array is full\n";}
		else {  
		int value = 8;
		arr[4] = value;
		n++;
		}
	}

int main()
{	
	display();
	cout<<endl;
	insert();
	cout<<endl;
	display();
	cout<<endl;
	insert();
	
	return 0;
}
