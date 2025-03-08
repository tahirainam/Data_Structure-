#include <iostream>
using namespace std;
class Calculator {
public:
    // Factorial Function
    int factorial(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
    // Summation Function
    int sum(int n) {
        if (n <= 1) {
            return n;
        } else {
            return n + sum(n - 1);
        }
    }
    // Recursive Fibonacci Function
    int fibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
    // Display Fibonacci Series Function
    void fibonacciSeries(int terms) {
        cout << "\n\tFibonacci Series: ";
        for (int i = 0; i < terms; ++i) {
            cout << fibonacci(i) << " ";
        }
        cout << endl;
    }
    // Power Function
    int power(int base, int exp) {
        if (exp == 0) {
            return 1;
        } else {
            return base * power(base, exp - 1);
        }
    }
};
int main() {
    Calculator calc;
    int choice;
    while(true) {
        cout << "\n\n\t=== Calculator Menu ===\n";
        cout << "\t1. Factorial\n";
        cout << "\t2. Summation\n";
        cout << "\t3. Fibonacci Series\n";
        cout << "\t4. Power\n";
        cout << "\t5. Exit\n";
        cout << "\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int num;
            cout << "\n\tEnter a number to calculate factorial: ";
            cin >> num;
            cout << "\tFactorial of " << num << " = " << calc.factorial(num) << endl;
            break;
        }
        case 2: {
            int num;
            cout << "\n\tEnter a number to calculate summation: ";
            cin >> num;
            cout << "\tSummation of numbers up to " << num << " = " << calc.sum(num) << endl;
            break;
        }
        case 3: {
            int terms;
            cout << "\n\tEnter the number of terms for the Fibonacci series: ";
            cin >> terms;
            calc.fibonacciSeries(terms);
            break;
        }
        case 4: {
            int base, exp;
            cout << "\n\tEnter the base number: ";
            cin >> base;
            cout << "\tEnter the exponent: ";
            cin >> exp;
            cout <<"\t"<< base << "^" << exp << " = " << calc.power(base, exp) << endl;
            break;
        }
        case 5:;
            cout << "\n\tExiting the program...\n";
            return 0; 
            break;
        default:
            cout << "\n\tInvalid choice! Please try again.\n";
        }
    }
    return 0;
}
