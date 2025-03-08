// doubly  linked list
//SONG STRUCTURE
// with PLATLIST CLASS
#include <iostream>
#include <string>
using namespace std;

struct Song {
	string artist_name, title;
	int duration, id;
	Song *next;
	Song *pre;
};

class Playlist {
	private:
		Song *head;
		Song *tail;
		int count, Tduration;
	public:
		// CONSTRUCTOR
		Playlist() {
			head = NULL;
			tail = NULL;
			count = 0;
			Tduration = 0;
		}
		//INSERTION
		void insertSong() {
			Song *temp = new Song;
			cout<<"\n\tEnter Artist Name: ";
			cin.ignore();
			getline(cin,temp->artist_name);
			cout<<"\n\tEnter Song Title: ";
			cin.ignore();
			getline(cin,temp->title);
			cout<<"\tEnter Duration: ";
			cin>>temp->duration;
			cout<<"\tEnter Song ID: ";
			cin>>temp->id;
			// TOTAL DURATION
			Tduration = Tduration + temp->duration;
			temp->next = NULL;
			temp->pre = NULL;
			if (head == NULL){
				head = temp;
				tail = temp;
			}
			else {
				tail->next = temp;
				temp->pre = tail;
				tail = temp;
			}
			// TOTAL SONGS/NODES
			count++;
		}
		//DISPLAYING
		void Display(){
			Song *temp = head;
			cout<<"\n\t-----------------------------------\n";
			while (temp != NULL){
				cout<<"\n\tSong ID: "<<temp->id;
				cout<<"\n\tSong Title: "<<temp->title;
				cout<<"\n\tArtist Name: "<<temp->artist_name;
				cout<<"\n\tSong Duration: "<<temp->duration<<endl;;
				
				temp = temp->next;
			}
			cout<<"\n\n\tTOTAL SONGS: "<<count<<endl;
			cout<<"\n\tTOTAL DURATION: "<<Tduration<<endl;
		    cout<<"\n\t-----------------------------------\n";

		}
		//SEARCHING
		void search(){
			int num, f = 0;
			cout<<"\n\tEnter Song ID to search: ";
			cin>>num;
			Song *temp = head;
			while (temp != NULL){
				if (temp->id == num ) {
					f = 1;
					break;
				}
				temp = temp->next;
			}
			if (f == 1){
				cout<<"\n\tSong Found\n";
				cout<<"\n\tSong ID: "<<temp->id;
				cout<<"\n\tSong Title: "<<temp->title;
				cout<<"\n\tArtist Name: "<<temp->artist_name;
				cout<<"\n\tSong Duration: "<<temp->duration;
			}
			else {
				cout<<"\n\tSong Not Found";
			}
		}
		//UPDATION
		void update(){
			int num, f = 0;
			cout<<"\n\tEnter Song ID to update: ";
			cin>>num;
			Song *temp = head;
			Song *temp2 = tail;
			while (temp != NULL){
				if (temp->id == num || temp2->id == num) {
					f = 1;
					break;
				}
				temp = temp->next;
				temp2 = temp2->next;
			}
			if (f==1) {
			int choice;
			do {
				cout<<"\n\t----UPDATE----";
				cout<<"\n\t0. Exit";
				cout<<"\n\t1. Update Artist Name";
				cout<<"\n\t2. Update Song Title";
				cout<<"\n\t3. Update Song Duration";
				cout<<"\n\t--------------\n";
				cout<<"\n\tEnter Choice: ";
				cin>>choice;
				switch (choice){
					case 0:
						cout<<"\n\tExiting from Updation...\n";
						break;
					case 1:
						cout<<"\n\tUpdate Artist Name: ";
			            cin>>temp->artist_name;
			            cout<<"\n\tArtist Name Updated successfuly\n";
			            break;
					case 2:
						cout<<"\n\tUpdate Song Title: ";
			            cin.ignore();
		                getline(cin, temp->title);
			            cout<<"\n\tSong Title Updated successfuly\n";
			            break;
					case 3:
						cout<<"\n\tUpdate Duration: ";
			            cin>>temp->duration;
			            cout<<"\n\tSong Duration Updated successfuly\n";
			            break;
			        default:
			        	cout<<"\n\tInvalid Choice. Try Again";
				}
			} while (choice != 0);
		}
		else {
			cout<<"\n\tRECORD NOT FOUND\n";
		}
		}
		//PLAY NEXT
		void next() {
			int num, f = 0;
			cout<<"\n\tEnter Song ID : ";
			cin>>num;
			Song *temp = head;
			while (temp != NULL){
				if (temp->id == num ) {
					f = 1;
					temp = temp->next;
					// To play next song
                    if (temp == NULL) {
                       cout << "\n\tNo More Songs\n";
                    } else {
                    	cout<<"\n\tSONG THAT WILL PLAY NEXT\n";
				        cout<<"\n\tSong ID: "<<temp->id;
				        cout<<"\n\tSong Title: "<<temp->title;
				        cout<<"\n\tArtist Name: "<<temp->artist_name;
				        cout<<"\n\tSong Duration: "<<temp->duration;
					}
					break;
				}
				temp = temp->next;
			}
			if (f == 0) {
               cout << "\n\tBook Not Found\n";
            }
		}
		//PLAY PREVIOUS
		void previous() {
			int num, f = 0;
			cout<<"\n\tEnter Song ID : ";
			cin>>num;
			Song *temp = head;
			while (temp != NULL){
				if (temp->id == num ) {
					f = 1;
					temp = temp->pre;
					// To play next song
                    if (temp == NULL) {
                       cout << "\n\tNo More Songs\n";
                    } else {
                    	cout<<"\n\tPREVIOUS SONG\n";
				        cout<<"\n\tSong ID: "<<temp->id;
				        cout<<"\n\tSong Title: "<<temp->title;
				        cout<<"\n\tArtist Name: "<<temp->artist_name;
				        cout<<"\n\tSong Duration: "<<temp->duration;
					}
					break;
				}
				temp = temp->next;
			}
			if (f == 0) {
               cout << "\n\tBook Not Found\n";
            }
		}
};

int main(){
	Playlist p;
	while (true) {
		cout<<"\n\n\t----MENU----\n";
		cout<<"\n\t1. INSERT A SONG";
		cout<<"\n\t2. DISPLAY PLAYLIST";
		cout<<"\n\t3. SEARCH A SONG";
		cout<<"\n\t4. UPDATE A SONG";
		cout<<"\n\t5. PLAY NEXT";
		cout<<"\n\t6. PLAY PREVIOUS";
		cout<<"\n\t7. Exit";
		int choice;
		cout<<"\n\n\tEnter Choice: ";
		cin>>choice;
		switch (choice)
		{
			case 1:
				p.insertSong();
				break;
			case 2:
				p.Display();
				break;
			case 3:
				p.search();
				break;
			case 4:
				p.update();
				break;
			case 5:
				p.next();
				break;
			case 6:
				p.previous();
				break;
			case 7:
				return 0;
				break;
			default:
				cout<<"\n\tINVALID INPUT\n";
		}
	}
	return 0;
}
