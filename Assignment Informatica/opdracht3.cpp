#include <iostream>

using namespace std;

int main(){

    cout << "Celcius to Fahrenheit" << endl;

    double celcius;
    cout << "Enter value for Celcius: ";
    cin >> celcius;

    double fahrenheit = (celcius * 9/5) + 32;
    cout << celcius << " degree Celcius is " << fahrenheit << " degree Fahrenheit." << endl;

    return 0;
}