#include <iostream>

using namespace std;

int main() {
    
    cout << "Calculator" << endl;

    double x, y;
    cout << "Enter value for x: ";
    cin >> x;
    cout << "Enter value for y: ";
    cin >> y;
    
    int operation;
    cout << "Do you want to 1. add, 2. subtract, 3. multiply or 4. divide?"<< endl;
    cout << "Choose an operation by number: ";
    cin >> operation;

    while (operation < 1 || operation > 4) {
        cout << "The number you have chosen is invalid. Try again. " << endl;
        cout << "Do you want to 1. add, 2. subtract, 3. multiply or 4. divide?"<< endl;
        cout << "Choose an operation by number: ";
        cin >> operation;
    }

    double add = x + y;
    double subtract = x - y;
    double multiply = x * y;
    double divide = x / y;

    switch (operation) {
    case 1 :
        cout << x << " + " << y << " = " << add;
        break;
    case 2 :
        cout << x << " - " << y << " = " <<  subtract;
        break;
    case 3: 
        cout << x << " * " << y << " = " << multiply;
        break;
    case 4:
        cout << x << " / " << y << " = " << divide;
    default:
        break;
    }

    return 0;
}