#include <iostream>
#include <string>
using namespace std;

struct Book {
    int bookID, quantity;
    string author;
    float price;
    Book *left;
    Book *right;
};

class Library {
private:
    Book *root;
    float total;

public:
    Library() {
        root = NULL;
        total = 0;
    }

    Book *insert(int id, string author, int quantity, float price, Book *temp) {
        if (temp == NULL) {
            temp = new Book;
            temp->bookID = id;
            temp->author = author;
            temp->quantity = quantity;
            temp->price = price;
            temp->left = NULL;
            temp->right = NULL;
            if (root == NULL) {
                root = temp;
            }
        } else if (price < temp->price) {
            temp->left = insert(id, author, quantity, price, temp->left);
        } else {
            temp->right = insert(id, author, quantity, price, temp->right);
        }
        return temp;
    }

    void lessQuantityBook(Book *temp) {
        if (temp != NULL) {
            lessQuantityBook(temp->left);
            if (temp->quantity < 2) {
                cout << "ID: " << temp->bookID << endl;
                cout << "Author: " << temp->author << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Price: " << temp->price << endl;
            }
            lessQuantityBook(temp->right);
        }
    }

    void price1000(Book *temp) {
        if (temp != NULL) {
            price1000(temp->left);
            if (temp->price > 1000) {
                cout << "ID: " << temp->bookID << endl;
                cout << "Author: " << temp->author << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "Price: " << temp->price << endl;
            }
            price1000(temp->right);
        }
    }

    void totalCost(Book *temp) {
        if (temp != NULL) {
            total += temp->price;
            totalCost(temp->left);
            totalCost(temp->right);
        }
    }

    void displayTotalCost() {
        total = 0;
        totalCost(root);
        cout << "Total Cost: " << total << endl;
    }

    Book *getRoot() {
        return root;
    }
};

int main() {
    Library L;
    int choice;

    while (true) {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books with Quantity Less Than 2\n";
        cout << "3. Display Books with Price Greater Than 1000\n";
        cout << "4. Display Total Cost of Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id, quantity;
            string name;
            float price;
            cout << "Enter Book ID: ";
            cin >> id;
            cout << "Enter Author Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Book Price: ";
            cin >> price;
            cout << "Enter Book Quantity: ";
            cin >> quantity;
            L.insert(id, name, quantity, price, L.getRoot());
            break;
        }
        case 2:
            cout << "\nBooks with Quantity Less Than 2:\n";
            L.lessQuantityBook(L.getRoot());
            break;
        case 3:
            cout << "\nBooks with Price Greater Than 1000:\n";
            L.price1000(L.getRoot());
            break;
        case 4:
            L.displayTotalCost();
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
