# Lab: Menu-driven Calculator

## Learning Outcomes
By the end of this lab, I can:
- Apply if/else and switch to implement menu options.
- Validate input and reject errors.
- Detect and handle division by zero.
- Use `enum class` for type-safe menu choices.
- Practice short-circuiting and scope control.
- Create an interactive calculator.

---

## Code (Calculator.cpp)

```cpp
#include <iostream>
#include <limits>   // for numeric_limits
using namespace std;

enum class MenuChoice {
    Add = 1,
    Subtract,
    Multiply,
    Divide,
    Quit
};

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

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

        double a = readDouble("Enter first number: ");
        double b = readDouble("Enter second number: ");

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

