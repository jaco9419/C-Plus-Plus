#include <iostream>

using namespace std;

int main()
{
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;
    double result;

    if(op == '+'){
        result = num1 + num2;
        cout << "Result: " << result << endl;
    } else if(op == '-'){
        result = num1 - num2;
        cout << "Result: " << result << endl;
    } else if(op == '*'){
        result = num1 * num2;
        cout << "Result: " << result << endl;
    } else if(op == '/'){
        result = num1 / num2;
        cout << "Result: " << result << endl;
    } else {
        cout << "You entered an invalid operator" << endl;
    }



    return 0;
}
