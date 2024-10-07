#include <iostream>
#include <iomanip> 
using namespace std;

int countOccurances(int arr[], int size, int n);
void sortArray(int arr[], int size);

int main() {
    int size = 0;
    int arr[50];

    // Reading values into the array until the user inputs -1
    cout << "Enter values (end with -1): ";
    int input;
    while (cin >> input && input != -1 && size < 50) {
        arr[size] = input;
        size++;
    }

    // Sort the array in descending order
    sortArray(arr, size);

    // Display the table header
    cout << left << setw(10) << "N" << setw(10) << "Count" << endl;

    // Count and print each unique element
    for (int i = 0; i < size; i++) {
        int count = countOccurances(arr, size, arr[i]);
        // Print the element and its count if it's the first occurrence
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

// Sort array in descending order
void sortArray(int *arr, int size) {
    int temp = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {  // Swap if the current is smaller than next
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

