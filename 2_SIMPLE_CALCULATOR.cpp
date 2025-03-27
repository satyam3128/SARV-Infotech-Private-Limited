#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2, result;

    cout << "Welcome to my Calculator!" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> operation;
    cout << "Enter second number: ";
    cin >> num2;

    switch (operation) {
    case '+':
        result = num1 + num2;
        cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
        break;
    case '-':
        result = num1 - num2;
        cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
        break;
    case '*':
        result = num1 * num2;
        cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
            cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
        break;
    default:
        cout << "Error: Invalid operator! Please use +, -, *, or /." << endl;
    }

    return 0;
}
