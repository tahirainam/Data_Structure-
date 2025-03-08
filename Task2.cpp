#include <iostream>
using namespace std;
int n=4; 
const int size = 5;
int arr[5]= {45, 55, 89, 90};

class InsertingAtStart {
	public:
	void shifting(){
	for (int i=n; i>=0; i--) {
			arr[i]=arr[i-1];}
}

    void display() {
		for (int i = 0; i<size; i++)
	    {
		cout<<arr[i]<<" ";	
	    }
    }
	void insertAtStart() {
		if (n>=size) {cout<<"\n\t array is full\n";}
		else {
			int value = 8;
			arr[0] = value;
	     	n++;
		}
	}
	
};

int main()
{	
InsertingAtStart IAS;
IAS.shifting();
	IAS.display();
	cout<<endl;
	IAS.insertAtStart();
	cout<<endl;
	IAS.display();
	cout<<endl;
	
	return 0;
}
