#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *ptr;
};

class Dstack {
private:
    Node *top;
public:
    Dstack() {
        top = NULL;
    }

    // INSERTION
    void push() {
        Node *temp = new Node;
        temp->data = '(';
        temp->ptr = NULL;
        if (top == NULL) {
            top = temp;
        } else {
            temp->ptr = top;
            top = temp;
        }
    }

    // DELETION
    void pop() {
        if (top == NULL) {
            cout << "\n\tUnderflowed\n";
        } else {
            char num = top->data;
            Node *temp = top;
            top = top->ptr;  
            delete temp; 
        }
    }

    // DISPLAY
    void display() {
        Node *temp = top;
        cout << "\n";
        while (temp != NULL) {
            cout << "\t" << temp->data;
            temp = temp->ptr;
        }
        cout << "\n";
    }

    // CHECKING BALANCED EXPRESSION
    void balancedExpression(string expression) {
        Dstack d;
        char i = 0;  
        char c;
        while (i < expression.length()) {
            c = expression[i];
            if (c == '(') {
                d.push();
            } else if (c == ')') {
                if (d.top == NULL) {
                    cout << "\n\tINVALID\n";
                    return; 
                }
                d.pop();
            }
            i++;
        }
        if (d.top == NULL) {
            cout << "\n\tVALID\n";
        } else {
            cout << "\n\tINVALID\n";
        }
    }
};

int main() {
    Dstack ds;
    while (true) {
        cout << "\n\n\tMENU\n";
        cout << "\t1. CHECKING BALANCED EXPRESSION\n";
        cout << "\t2. EXIT";
        int choice;
        cout << "\n\tChoice? ";
        cin >> choice;
        switch (choice) {
            case 1:
                ds.balancedExpression("(98*0)");
                break;
            case 2:
                return 0;
                break;
            default:
                cout << "\n\tInvalid Input";
        }
    }

    return 0;
}
