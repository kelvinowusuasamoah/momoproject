#include <iostream>

using namespace std;

int main() {
    // Default Pin and Balance
    int pin = 0000;
    double balance = 1000.00;

    // Authentication
    int attempts = 0;
    while (attempts < 3) {
        int input_pin;
        cout << "Please enter your PIN: ";
        cin >> input_pin;
        if (input_pin == pin) {
            cout << "Authentication successful!" << endl;
            break;
        } else {
            attempts++;
            cout << "Invalid PIN! You have " << 3 - attempts << " attempts remaining." << endl;
        }
    }
    if (attempts == 3) {
        cout << "You have exceeded the maximum number of attempts. Program will now exit." << endl;
        return 0;
    }

    // Options Menu
    int option;
    while (true) {
        cout << "\nPlease select an option to continue:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Change PIN" << endl;
        cout << "4. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        if (option == 1) { // Check Balance
            cout << "Your current balance is: Php" << balance << endl;
        } else if (option == 2) { // Withdraw Money
            double amount;
            cout << "Please enter the amount to withdraw: Php";
            cin >> amount;
            if (amount > balance) {
                cout << "Insufficient balance!" << endl;
            } else {
                balance -= amount;
                cout << "Withdrawal successful! Your new balance is: Php" << balance << endl;
            }
        } else if (option == 3) { // Change Pin
            int new_pin;
            cout << "Please enter your new PIN: ";
            cin >> new_pin;
            pin = new_pin;
            cout << "PIN successfully changed!" << endl;
        } else if (option == 4) { // Exit
            cout << "Program will now exit. Thank you!" << endl;
            break;
        } else { // Invalid Option
            cout << "Invalid option selected. Please try again." << endl;
        }
    }
    return 0;
}        
