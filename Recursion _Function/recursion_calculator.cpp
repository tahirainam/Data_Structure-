#include <iostream>
using namespace std;

class Calculation {
public:
    // FACTORIAL
    int fact(int n) {
        if (n == 1 || n == 0) {
            return 1;
        } else {
            int fac = n * fact(n - 1);
            return fac;
        }
    }

    // SUMMATION
    int sum(int n) {
        if (n == 1) {
            return 1;
        } else {
            int sm = n + sum(n - 1);
            return sm;
        }
    }
};

int main() {
    Calculation cal;
    int choice, num;

    do {
        cout << "Menu:" << endl;
        cout << "1. Calculate Factorial" << endl;
        cout << "2. Calculate Sum of Numbers" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter a number to find factorial: ";
            cin >> num;
            cout << "Factorial of " << num << " = " << cal.fact(num) << endl;
            break;
        case 2:
            cout << "Enter a number to find sum: ";
            cin >> num;
            cout << "Sum of " << num << " and all previous numbers = " << cal.sum(num) << endl;
            break;
        case 3:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
