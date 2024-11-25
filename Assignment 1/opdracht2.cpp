#include <iostream>

using namespace std;

int main() {

   cout << "Age calculator" << endl;

   int yearOfBirth;
   cout << "Enter your year of birth: ";
   cin >> yearOfBirth;

   const int currentYear = 2024;
   int age = currentYear - yearOfBirth;

   cout << "You are " << age << " years old." << endl;

   return 0;
}