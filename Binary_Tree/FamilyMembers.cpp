#include <iostream>
#include <string>
using namespace std;

struct familyMember {
    string name;
    int age;
    familyMember *left;
    familyMember *right;
};

class Family {
private:
    familyMember *root;

public:
    Family() {
        root = NULL;
    }

    familyMember *insert(int age, string name, familyMember *temp) {
        if (temp == NULL) {
            temp = new familyMember;
            temp->age = age;
            temp->name = name;
            temp->left = NULL;
            temp->right = NULL;
            if (root == NULL) {
                root = temp;
            }
        } else if (age < temp->age) {
            temp->left = insert(age, name, temp->left);
        } else {
            temp->right = insert(age, name, temp->right);
        }
        return temp;
    }

    void preOrder(familyMember *temp) {
        if (temp != NULL) {
            cout << "Age: " << temp->age << ", Name: " << temp->name << "\n";
            preOrder(temp->left);
            preOrder(temp->right);
        }
    }

    void postOrder(familyMember *temp) {
        if (temp != NULL) {
            postOrder(temp->left);
            postOrder(temp->right);
            cout << "age: " << temp->age << ", Name: " << temp->name << "\n";
        }
    }

    void inOrder(familyMember *temp) {
        if (temp != NULL) {
            inOrder(temp->left);
            cout << "Age: " << temp->age << ", Name: " << temp->name<< "\n";
            inOrder(temp->right);
        }
    }

    familyMember *search(string name, familyMember *temp) {
        if (temp == NULL || temp->name == name) {
            return temp;
        } else if (name == temp->name) {
            return search(name, temp->left);
        } else {
            return search(name, temp->right);
        }
    }
    
    familyMember *update(int oldAge, int Nage, familyMember *temp) {
        if (temp == NULL || temp->age == oldAge) {
        	
            return temp;
        } else if (oldAge == temp->age) {
            return update(oldAge, Nage, temp->left);
        } else {
            return update(oldAge, Nage, temp->left);
        }
    }

    familyMember *getRoot() {
        return root;
    }
};

int main() {
    Family st;
    while (true) {
        cout << "\nMenu\n";
        cout << "1. Insert Family Member\n";
        cout << "2. Display Pre Order\n";
        cout << "3. Display Post Order\n";
        cout << "4. Display In Order\n";
        cout << "5. Search Family Member\n";
        cout << "6. Update Family Member age\n";
        cout << "7. Exit\n";
        int choice;
        cout << "Choice? ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int age;
            string name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Member Name: ";
            cin.ignore();
            getline(cin, name);
            st.insert(age, name, st.getRoot());
            break;
        }
        case 2:
            cout << "Pre Order Display:\n";
            st.preOrder(st.getRoot());
            break;
        case 3:
            cout << "Post Order Display:\n";
            st.postOrder(st.getRoot());
            break;
        case 4:
            cout << "In Order Display:\n";
            st.inOrder(st.getRoot());
            break;
        case 5: {
            string name;
            cout << "Enter name to Search: ";
            cin.ignore();
            getline(cin, name);
            familyMember *result = st.search(name, st.getRoot());
            if (result != NULL) {
                cout << "Member Found! Name: " << result->name<< "\n";
            } else {
                cout << "Member with Name " << name << " not found.\n";
            }
            break;
        }
        case 6: {
            int oldAge, NAge;
            cout << "Enter Age to Update: ";
            cin>>oldAge;
            cout << "Enter NEW Age to Update: ";
            cin>>NAge;
            familyMember *result = st.update(oldAge, NAge, st.getRoot());
            if (result != NULL) {
                cout << "Update! Age: " << "\n";
            } else {
                cout << "Member with Age " << oldAge << " not found.\n";
            }
            break;
        }
        case 7:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
