#include<iostream>
using namespace std;

class Student{
	private:
		const int size=10;
		int marks[10];
		int index=0;
		
	public:
		void insert(int x){
			if(index>=size){
				cout<<"Array is full";
			}
			marks[index]=x;
			index++;
		}
	void display(){
		for(int i=0;i<index;i++){
			cout<<marks[i];
		}
	}
	                      
    int deleteValue(int y) {
    for (int i = 0; i < index; i++) {
        if (marks[i] == y) { 
      
            for (int j = i; j < index - 1; j++) { 
                marks[j] = marks[j + 1];
            }
            index--; 
            return y; 
        }
    }
    cout << "Value not found" << endl; 
    return -1; 
}

           
                   
	void update(int oldV, int newV){
		int found=0;
		for(int i=0;i<10;i++){
			if(marks[i]==oldV){
				marks[i]=newV;
				cout << "Element at index " << i << " updated to " << newV << endl;
				found=1;
			}
		}
		if(found==0)
				cout<<"Not found!";
		}

	
	void search(int value) {
       int found = 0; 
        for (int i = 0; i < 10; i++) {
            if (marks[i] == value) {
                cout << "Value " << value << " found at index: " << i << endl;
                found = 1; 
            }
        }
        if (found==0) {         
            cout << "Value " << value << " not found!" << endl; 
        }
    }
	
	
	
};




int main(){
	
	Student s;
	int choice;
	
	while(true){
		cout<<"1. Insert "<<endl;
		cout<<"2. Display "<<endl;
		cout<<"3. Update "<<endl;
		cout<<"4. Search"<<endl;
		cout<<"5. Delete"<<endl;
		cout<<"6. Exit"<<endl;  
		cin>>choice;
		switch(choice){
		
			case 1:
				int value;
				cin>>value;
				s.insert(value);
				break;
		case 2: s.display(); break;

		case 3: 
			int Ovalue;
				cin>>Ovalue;	int Nvalue;
				cin>>Nvalue;
		s.update(Ovalue, Nvalue); break;
		case 4:
			int v; cin>>v;
			s.search(v); break;
			case 5: int r; cin>>r;
			s.deleteValue(r);break;
		        
				case 6: return 0; break;
		                    
			cout<<"Invalid input";
		}
			
		               
	}
	
	return 0;
}