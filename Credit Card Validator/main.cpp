#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to apply Luhn Algorithm
bool isValidCardNumber(const string& cardNumber) {
    int sum = 0;
    bool doubleDigit = false;

    // Traverse the number from right to left
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        if (!isdigit(cardNumber[i])) {
            return false; // Non-digit character detected
        }

        int digit = cardNumber[i] - '0';

        if (doubleDigit) {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }

        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10 == 0);
}

int main() {
    string cardNumber;

    cout << "Enter your credit card number (no spaces or dashes): ";
    cin >> cardNumber;

    if (isValidCardNumber(cardNumber)) {
        cout << "✅ Valid credit card number.\n";
    } else {
        cout << "❌ Invalid credit card number.\n";
    }

    return 0;
}
