#include <iostream>
using namespace std;

int main() {
    // City names
    string cities[] = {"Lahore", "Sialkot", "Islamabad", "Murree"};

    // Ticket prices between cities (instead of distances)
    int ticketPrices[4][4] = {
        {0, 500, 800, 0},   // From Lahore
        {600, 0, 0, 0},     // From Sialkot
        {0, 700, 0, 1000},  // From Islamabad
        {0, 0, 900, 0}      // From Murree
    };

    // Display ticket prices between cities
    cout << "Ticket prices between cities:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (ticketPrices[i][j] != 0) {
                cout << "From " << cities[i] << " to " << cities[j] << " = " 
                     << ticketPrices[i][j] << " PKR\n";
            }
        }
    }

    // Show ticket price from Islamabad to Sialkot
    cout << "\nTicket price from Islamabad to Sialkot: ";
    if (ticketPrices[2][1] != 0) {
        cout << ticketPrices[2][1] << " PKR\n";
    } else {
        cout << "No direct route available.\n";
    }

    return 0;
}

//sawrry i'm just a girl :)