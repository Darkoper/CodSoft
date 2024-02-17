#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        char op;
        double num1, num2;

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch(op) {
            case '+':
                cout << "Result: " << num1 + num2;
                break;
            case '-':
                cout << "Result: " << num1 - num2;
                break;
            case '*':
                cout << "Result: " << num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                    cout << "Result: " << num1 / num2;
                else
                    cout << "Error! Division by zero!";
                break;
            default:
                cout << "Error! Invalid operator!";
                break;
        }

        cout << "\n\nDo you want to use the calculator again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
