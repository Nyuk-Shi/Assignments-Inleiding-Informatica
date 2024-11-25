#include <iostream>

using namespace std;

int main() {

    cout << "x + y = " << endl;

    double x, y;
    cout << "Enter value for x: ";
    cin >> x;
    cout << "Enter value for y: ";
    cin >> y;

    double z = x + y;
    cout << x << " + " << y << " = "<< z << endl;

    return 0;
}