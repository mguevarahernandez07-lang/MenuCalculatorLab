#include <iostream>
#include <limits>   // for numeric_limits
using namespace std;

// Define an enum class for menu choices
enum class MenuChoice {
    Add = 1,
    Subtract,
    Multiply,
    Divide,
    Quit
};

// Function to safely read a double with validation
double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    }
}

// Function to display the menu
void showMenu() {
    cout << "\n===== Calculator Menu =====\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Quit\n";
    cout << "Choose an option (1-5): ";
}

int main() {
    while (true) {
        showMenu();
        int choiceInt;
        cin >> choiceInt;

        if (cin.fail() || choiceInt < 1 || choiceInt > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        MenuChoice choice = static_cast<MenuChoice>(choiceInt);

        if (choice == MenuChoice::Quit) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        // Read operands
        double a = readDouble("Enter first number: ");
        double b = readDouble("Enter second number: ");

        // Perform the selected operation
        switch (choice) {
            case MenuChoice::Add:
                cout << "Result: " << a + b << endl;
                break;
            case MenuChoice::Subtract:
                cout << "Result: " << a - b << endl;
                break;
            case MenuChoice::Multiply:
                cout << "Result: " << a * b << endl;
                break;
            case MenuChoice::Divide:
                if (b == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                } else {
                    cout << "Result: " << a / b << endl;
                }
                break;
            default:
                cout << "Unexpected error." << endl;
                break;
        }
    }
    return 0;
}
