#include <iostream>
#include <iomanip>
#include <sstream> 

using namespace std;

int countOccurances(int arr[], int size, int n);
void sortArray(int arr[], int size);

int main() {
    int size = 0;
    int arr[50];
    string input;

    // Read values until "done" is typed
    cout << "Enter values followed by 'done' to finish: ";

    while (cin >> input && input != "done" && size < 50) {
        stringstream ss(input);
        int value;
        ss >> value;
        
        // Skip if input is invalid
        if (ss.fail()) {
            cout << "Invalid input, please enter a number or 'done'." << endl;
            continue;
        }
        
        arr[size] = value;
        size++;
    }

    // Sort the array
    sortArray(arr, size);

    cout << left << setw(10) << "N" << setw(10) << "Count" << endl;

    // Count and print each unique value
    for (int i = 0; i < size; i++) {
        int count = countOccurances(arr, size, arr[i]);
        if (i == 0 || arr[i] != arr[i - 1]) {
            cout << left << setw(10) << arr[i] << setw(10) << count << endl;
        }
    }

    return 0;
}

// Count occurrences of a number
int countOccurances(int *arr, int size, int n) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == n) {
            count++;
        }
    }
    return count;
}

// Sort the array in descending order
void sortArray(int *arr, int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
