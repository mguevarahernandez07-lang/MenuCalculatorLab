# Lab: Menu-driven Calculator
## Reflection on Challenges

When I started this lab, the hardest part was making sure the calculator did not crash when I typed something that was not a number. At first it kept breaking, but then I learned to clear the input and ignore the bad text so it would ask me again.

Another challenge was division. If the second number was zero, the calculator gave an error, so I had to add a special check to stop it. This taught me how to handle problems before they happen.

I also had to use an enum class for the menu. At first it was confusing because I had to change the number choice into the enum type, but after I figured it out, it made the menu safer and easier to use.

I liked using a switch statement because it looked cleaner than a lot of if/else statements. It made the program easier to read.

Overall, the lab was a little tricky at first, but after fixing input and division problems, the calculator worked the way I wanted.

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

## Paste video link here

```
Video link here
```
https://app.screencastify.com/watch/CIduiGTpIRwIpQzLcWyi

**End of exercise**
