#include <iostream>
using namespace std;

class Cir_queue {
private:
    int front, rear, arr[5], maxsize, counter;

public:
    Cir_queue() {
        front = 0;
        rear = -1;
        maxsize = 5;
        counter = 0;
    }

    void enqueue() {
        if (counter >= maxsize) {
            cout << "\n\tQueue is full";
        } else {
            rear = (rear + 1) % maxsize;
            cout << "\n\tEnter Data: ";
            cin >> arr[rear];
            counter++;
        }
    }

    int dequeue() {
        if (counter == 0) {
            cout << "\n\tQueue is Empty";
        } else {
            int num = arr[front];
            front = (front + 1) % maxsize;
            counter--;
            cout << "\n\tDequeued: " << num;
            return num;
        }
    }

    void display() {
        if (counter == 0) {
            cout << "\n\tQueue is Empty";
        } else {
            cout << "\n\tQueue elements are: ";
            for (int i = 0; i < counter; i++) {
                 int index = (front + i) % maxsize;
                cout << arr[index] << "\t";
            }
        }
    }
};

int main() {
    Cir_queue cq;
    while (true) {
        cout << "\n\t----MENU----\n";
        cout << "\n\t1. Insert";
        cout << "\n\t2. Delete";
        cout << "\n\t3. Display";
        cout << "\n\t4. Exit";
        int choice;
        cout << "\n\tEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cq.enqueue();
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.display();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "\n\tInvalid Input\n";
        }
    }
    return 0;
}
