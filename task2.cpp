#include <iostream>
using namespace std;

int num1, num2, result;
char operation; 

int main() {
    cout << "Welcome to Basic Calculator @ CodSoft! \n";
    cout << "Enter your two numbers: \n";

    cin >> num1;
    cin >> num2;

    cout << "Choose your operation (+, -, *, /): \n";
    cin >> operation; 

    switch (operation) {
    case '+':
        result = num1 + num2;
        cout << "The result is: " << result << endl;
        break;

    case '-':
        result = num1 - num2;
        cout << "The result is:  " << result << endl;
        break;

    case '/':
        if (num2 != 0) {
        result = num1 / num2;
        cout << "The result is:  " << result << endl;
        } else {
        cout << "Division by zero is not allowed!" << endl;
        }
        break;

    case '*':
        result = num1 * num2;
        cout << "The result is:  " << result << endl;
        break;

    default:
        cout << "Invalid Operation! \n";
    }

    return 0;
}
