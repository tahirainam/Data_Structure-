#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ID;
    string name;
    float balance;
    string status; // Current or Saving
    Node *left;
    Node *right;
};

class Bank_Tree {
private:
    Node *root;
    float total;

public:
    Bank_Tree() {
        root = NULL;
        total = 0;
    }

    Node *insert(int id, string nm, float blnc, string st, Node *temp) {
        if (temp == NULL) {
            temp = new Node;
            temp->ID = id;
            temp->name = nm;
            temp->balance = blnc;
            temp->status = st;
            temp->left = NULL;
            temp->right = NULL;
            if (root == NULL) {
                root = temp;
            }
        } else if (temp->balance > blnc) {
            temp->left = insert(id, nm, blnc, st, temp->left);
        } else {
            temp->right = insert(id, nm, blnc, st, temp->right);
        }
        return temp;
    }

    void max_balance(Node *temp) {
        if (temp == NULL) {
            cout << "No accounts available.\n";
            return;
        }
        if (temp->right == NULL) {
            cout <<"\n\t"<< temp->ID << endl;
            cout <<"\n\t"<< temp->name << endl;
            cout <<"\n\t"<< temp->balance << endl;
            cout <<"\n\t"<< temp->status << endl;
        } else {
            max_balance(temp->right);
        }
    }

    void total_amount(Node *temp) {
        if (temp != NULL) {
            total += temp->balance;
            total_amount(temp->left);
            total_amount(temp->right);
        }
    }

    void display_total() {
        total = 0;
        total_amount(root);
        cout << "\n\tTotal amount in Bank: " << total << endl;
    }

    void Saving_account(Node *temp) {
    	if (temp == NULL) {
            cout << "No accounts available.\n";
            return;
        }
        if (temp != NULL) {
            if (temp->status == "saving") {
                cout <<"\n\t"<< temp->ID << endl;
                cout <<"\n\t"<< temp->name << endl;
                cout <<"\n\t"<< temp->balance << endl;
                cout <<"\n\t"<< temp->status << endl;
            }
            Saving_account(temp->left);
            Saving_account(temp->right);
        }
    }

    void deduct_zakat(Node *temp) {
        if (temp != NULL) {
            if (temp->status == "current") {
                temp->balance -= temp->balance * 0.025;
            }
            deduct_zakat(temp->left);
            deduct_zakat(temp->right);
        }
    }

    void add_profit(Node *temp) {
        if (temp != NULL) {
            if (temp->status == "saving") {
                temp->balance += temp->balance * 0.05;
            }
            add_profit(temp->left);
            add_profit(temp->right);
        }
    }
    // credit and debit amount
    void credit_debit(Node *temp, int id, float amount, bool isCredit) {
    if (temp == NULL) {
        cout << "Account not found.\n";
        return;
    }

    if (temp->ID == id) {
        if (isCredit) {
            temp->balance += amount;
            cout << "Amount credited successfully. New balance: " << temp->balance << endl;
        } else {
            if (temp->balance >= amount) {
                temp->balance -= amount;
                cout << "Amount debited successfully. New balance: " << temp->balance << endl;
            } else {
                cout << "Insufficient balance. Transaction failed.\n";
            }
        }
    } else if (id < temp->ID) {
        credit_debit(temp->left, id, amount, isCredit);
    } else {
        credit_debit(temp->right, id, amount, isCredit);
    }
}

//get root
    Node *getRoot() {
        return root;
    }
};

int main() {
    Bank_Tree bt;
    while (true) {
        cout << "\n\tMENU\n";
        cout << "\n\t1. Insert Account";
        cout << "\n\t2. Accounts with Max Balance";
        cout << "\n\t3. Total Amount in Bank";
        cout << "\n\t4. Saving Accounts";
        cout << "\n\t5. Deduct Zakat";
        cout << "\n\t6. Add profit of 5%";
        cout << "\n\t7. Credit & Debit Amount";
        cout << "\n\t8. Exit";
        int choice;
        cout << "\n\tEnter Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int id;
            string nm;
            float blnc;
            string st;
            cout << "\n\tEnter ID: ";
            cin >> id;
            cout << "\tEnter Account Holder Name: ";
            cin.ignore();
            getline(cin, nm);
            cout << "\tEnter Balance: ";
            cin >> blnc;
            cout << "\tEnter Status (current/saving): ";
            cin >> st;
            bt.insert(id, nm, blnc, st, bt.getRoot());
            break;
        }
        case 2:
            bt.max_balance(bt.getRoot());
            break;
        case 3:
            bt.display_total();
            break;
        case 4:
            bt.Saving_account(bt.getRoot());
            break;
        case 5:
            bt.deduct_zakat(bt.getRoot());
            break;
        case 6:
            bt.add_profit(bt.getRoot());
            break;
        case 7:
            int id;
            float amount;
            int operation;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter 1 for Credit or 2 for Debit: ";
            cin >> operation;
            cout << "Enter Amount: ";
            cin >> amount;

            if (operation == 1) {
               bt.credit_debit(bt.getRoot(), id, amount, true); // Credit operation
            } else if (operation == 2) {
               bt.credit_debit(bt.getRoot(), id, amount, false); // Debit operation
            } else {
               cout << "Invalid operation.\n";
            }
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
