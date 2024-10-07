#include <iostream>
#include <cstring> 
using namespace std;

int main() {
    string first, second;
    int added[20]; 
    int carry = 0; 

    // Get the values
    cout << "Enter the first number (up to 20 digits): ";
    cin >> first;
    cout << "Enter the second number (up to 20 digits): ";
    cin >> second;

    // Reverse the numbers 
    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());

    // Initialize the result array 
    memset(added, 0, sizeof(added));

    int i = 0; // Index for the result
    int len1 = first.length(), len2 = second.length();
    int max_len = max(len1, len2); // Maximum length 

    // Add digits by one
    while (i < max_len || carry > 0) {
        int digit1 = (i < len1) ? first[i] - '0' : 0;  // Get digit from first 
        int digit2 = (i < len2) ? second[i] - '0' : 0; // Get digit from second 

        int sum = digit1 + digit2 + carry;  // Add digits
        added[i] = sum % 10;  // Store the digit
        carry = sum / 10;     // Update 

        i++; // Next digit
    }

    // Output in reverse
    cout << "Sum: ";
    bool leadingZero = true;  // Skip zeros
    for (int j = 19; j >= 0; --j) {
        if (added[j] != 0 || !leadingZero) {
            cout << added[j];
            leadingZero = false; // First non-zero stop skipping
        }
    }

    // If all zeros output '0'
    if (leadingZero) {
        cout << "0";
    }

    cout << endl;
    return 0;
}

