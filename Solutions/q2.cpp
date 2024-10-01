#include <iostream>
using namespace std;
bool isFull(char seatChart[7][5]);
void checkSeat(char seatChart[7][5], int row, char seat);
void printSeats(char seatChart[7][5]);

int main() {
    // Seating chart with 7 rows and 4 seats
    char seatChart[7][5] = {
        {'1', 'A', 'B', 'C', 'D'},
        {'2', 'A', 'B', 'C', 'D'},
        {'3', 'A', 'B', 'C', 'D'},
        {'4', 'A', 'B', 'C', 'D'},
        {'5', 'A', 'B', 'C', 'D'},
        {'6', 'A', 'B', 'C', 'D'},
        {'7', 'A', 'B', 'C', 'D'}
    };

    int row = 0;
    char seat = ' ';
    char enterAgain = 'N';

    do {
        printSeats(seatChart); // Display current seat availability

        // Prompt user for row
        cout << "Enter row number (1-7): ";
        cin >> row;
        while (row < 1 || row > 7) {
            cout << "Invalid input. Enter a value between 1 and 7: ";
            cin >> row;
        }

        // Prompt user for seat
        cout << "Enter seat letter (A-D): ";
        cin >> seat;
        while (seat < 'A' || seat > 'D') {
            cout << "Invalid input. Enter A, B, C, or D: ";
            cin >> seat;
        }

        // Check seat availability
        checkSeat(seatChart, row, seat);

        // Ask if the user wants to book again
        cout << "\nWould you like to book another seat? (Y/N): ";
        cin >> enterAgain;
    } while (enterAgain == 'Y' && !isFull(seatChart)); // Continue if not full

    // Check if all seats are booked
    if (isFull(seatChart))
        cout << "Sorry, there are no more empty seats on this plane." << endl;

    return 0;
}

// Check if all seats are booked
bool isFull(char seatChart[7][5]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 1; j < 5; j++) { // Check seats A-D
            if (seatChart[i][j] != 'X') 
                return false;
        }
    }
    return true; // All seats are booked
}

// Check seat availability and update the seat chart
void checkSeat(char seatChart[7][5], int row, char seat) {
    int seatIndex = seat - 'A' + 1; // Convert seat letter to index (1-4)

    if (seatChart[row - 1][seatIndex] == 'X') { // Check if seat is booked
        cout << "Sorry, seat " << row << seat << " is already taken." << endl;
    } else {
        seatChart[row - 1][seatIndex] = 'X'; // Mark as booked
        cout << "Congratulations! You've successfully booked seat " << row << seat << "." << endl;
    }
}

// Print available seats
void printSeats(char seatChart[7][5]) {
    cout << "AVAILABLE SEATS:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << seatChart[i][0] << " "; 
        for (int j = 1; j < 5; j++) { 
            cout << seatChart[i][j] << " ";
        }
        cout << endl; 
    }
}

