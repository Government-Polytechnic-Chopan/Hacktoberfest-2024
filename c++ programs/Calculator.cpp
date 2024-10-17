#include <iostream>
#include <cmath>
using namespace std;

void add(float a, float b) {
    cout << a << " + " << b << " = " << a + b << endl;
}

void subtract(float a, float b) {
    cout << a << " - " << b << " = " << a - b << endl;
}

void multiply(float a, float b) {
    cout << a << " * " << b << " = " << a * b << endl;
}

void divide(float a, float b) {
    if (b != 0)
        cout << a << " / " << b << " = " << a / b << endl;
    else
        cout << "Error! Division by zero." << endl;
}

void power(float a, float b) {
    cout << a << " ^ " << b << " = " << pow(a, b) << endl;
}

void squareRoot(float a) {
    if (a >= 0)
        cout << "Square root of " << a << " = " << sqrt(a) << endl;
    else
        cout << "Error! Square root of a negative number is not real." << endl;
}

int main() {
    char operation;
    float num1, num2;

    cout << "Enter operator (+, -, *, /, ^, s for square root): ";
    cin >> operation;

    if (operation == 's') {
        cout << "Enter a number: ";
        cin >> num1;
        squareRoot(num1);
    } else {
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) {
            case '+':
                add(num1, num2);
                break;
            case '-':
                subtract(num1, num2);
                break;
            case '*':
                multiply(num1, num2);
                break;
            case '/':
                divide(num1, num2);
                break;
            case '^':
                power(num1, num2);
                break;
            default:
                cout << "Invalid operator!" << endl;
                break;
        }
    }

    return 0;
}
