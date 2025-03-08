#include <iostream>
#include <string>
using namespace std;
struct Node {
    string songName;
    Node* next;
};
class Playlist {
public:
    Node* head;
    Node* tail;
    Playlist() {
        head = NULL;
        tail = NULL;
    }
    // Function to add a song to the playlist
    void insert() {
        Node* temp = new Node;
        cout << "\n\tEnter Song Name: ";
        cin.ignore();
        getline(cin, temp->songName);
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        cout << "\n\tSong added successfully!" << endl;
    }
    // Recursive function to traverse the playlist in forward order
    void traverseForward(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << "\t" << node->songName << endl;
        traverseForward(node->next);
    }
    // Recursive function to traverse the playlist in reverse order
    void traverseReverse(Node* node) {
        if (node == NULL) {
            return;
        }
        traverseReverse(node->next);
        cout << "\t" << node->songName << endl;
    }
    // Function to print the playlist in forward order using recursion
    void displayForward() {
        cout << "\n\tPlaylist in Forward Order:" << endl;
        traverseForward(head);
    }
    // Function to print the playlist in reverse order using recursion
    void displayReverse() {
        cout << "\n\tPlaylist in Reverse Order:" << endl;
        traverseReverse(head);
    }
};
// MAIN FUNCTION
int main() {
    Playlist p;
    while (true) {
        cout << "\n\tMENU\n";
        cout << "\n\t1. ADD SONG";
        cout << "\n\t2. DISPLAY PLAYLIST IN FORWARD ORDER";
        cout << "\n\t3. DISPLAY PLAYLIST IN REVERSE ORDER";
        cout << "\n\t4. EXIT\n";
        int choice;
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                p.insert();
                break;
            case 2:
                p.displayForward();
                break;
            case 3:
                p.displayReverse();
                break;
            case 4:
                return 0;
            default:
                cout << "\n\tINVALID CHOICE! Please try again." << endl;
        }
    }
    return 0;
}
