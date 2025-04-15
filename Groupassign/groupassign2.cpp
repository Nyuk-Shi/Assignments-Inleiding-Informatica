#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

/*
actions to be done:
store student names, IDs , and Grades
compute and display student average grades
assign letter grades base on scores
save and retrieve student data from file
*/


int searchIDs(int studentIDs[], int sizeIDs, int element);

void displayGrades(double subject1, double subject2, double subject3);

void displayLetterGrade(double subject1, double subject2, double subject3);

char convertGrade(double subject);

void printData(string_view studentName, string_view studentLastName, double subject1, double subject2, double subject3, double average);

double calcAverage(int size, double total);

int main(){

    string_view studentsLastNames[] = {"Wartim", "Warsosemito", "Purperhart"};
    string_view studentNames[] = {"Donovan", "Argeo", "Nyuk-Shi"};
    int studentIDs[] = {20240121, 20240407, 20241102};
    int sizeIDs = sizeof(studentIDs)/sizeof(studentIDs[0]);
    int myID;
    int indexID;
    int choice;

    do{
        cout << "Please fill in your student ID: ";
        cin >> myID;

        indexID = searchIDs(studentIDs, sizeIDs, myID);

        if (indexID == -1)
        {
            cout << myID << " is not in the database\n\n";
        }

    } while (indexID == -1);

    string_view studentName = studentNames[indexID];
    string_view studentLastName = studentsLastNames[indexID];

    int gradesIndex = indexID + 1;
    double gradesStudent[3];
    int sizeGrades = sizeof(gradesStudent)/sizeof(gradesStudent[0]);

    switch (gradesIndex){
        case 1:
            gradesStudent[0] = {8.0};
            gradesStudent[1] = {7.8};
            gradesStudent[2] = {9.0};
            break;
        case 2:
            gradesStudent[0] = {8.0};
            gradesStudent[1] = {6.7};
            gradesStudent[2] = {8.5};
            break;
        case 3:
            gradesStudent[0] = {6.5};
            gradesStudent[1] = {8.8};
            gradesStudent[2] = {8.9};
            break;
    }

    double subject1 = gradesStudent[0];
    double subject2 = gradesStudent[1];
    double subject3 = gradesStudent[2];
    double gradesTotal = subject1 + subject2 + subject3;

    double averageGrade = calcAverage(sizeGrades, gradesTotal);

    cout << "\nWelcome " << studentName << " " << studentLastName << " " << myID << '\n';

    do
    {
        cout << "Do you want to: \n";
        cout << "1. View your grades \n";
        cout << "2. View your grades in letter grades \n";
        cout << "3. Calculate your average score \n";
        cout << "4. Print out your data \n";
        cout << "5. Exit\n";
        cin >> choice;

        switch(choice){
            case 1:
                displayGrades(subject1, subject2, subject3);
                break;
            case 2:
                displayLetterGrade(subject1, subject2, subject3);
                break;
            case 3:
                cout << "Your Average score is: " << setprecision(1) << fixed  << averageGrade <<'\n';
                cout << "In lettergrade that is: " << convertGrade(averageGrade) << '\n';
                break;
            case 4:
                printData(studentName, studentLastName, subject1, subject2, subject3, averageGrade);
                break;
            case 5:
                break;
            default:
                cout << "That is not a valid choice\n\n";
                break;
        }

    } while (choice != 5);
    
    cout << "Thanks for visiting!\n";

    return 0;
}

int searchIDs(int studentIDs[], int sizeIDs, int element){
    for (int i = 0; i < sizeIDs; i++)
    {
        if (studentIDs[i] == element)
        {
            return i;
        }
        
    }
    return -1;
}

void displayGrades(double subject1, double subject2, double subject3){
    int columnwidth (30);
    cout << left;
    cout << setfill ('.');
    cout << setw (columnwidth) << "Subject" << setw (columnwidth) << "Grade" << endl;
    cout << setw (columnwidth) << "Subject 1"  << setw (columnwidth) << subject1 << endl;
    cout << setw (columnwidth) << "Subject 2" << setw (columnwidth) << subject2 << endl;
    cout << setw (columnwidth) << "Subject 3" << setw (columnwidth) << subject3 << endl;
}

void displayLetterGrade(double subject1, double subject2, double subject3){

    int columnwidth (30);
    cout << left;
    cout << setfill ('.');
    cout << setw (columnwidth) << "Subject" << setw (columnwidth) << "Grade" << endl;
    cout << setw (columnwidth) << "Subject 1"  << setw (columnwidth) << convertGrade(subject1) << endl;
    cout << setw (columnwidth) << "Subject 2" << setw (columnwidth) << convertGrade(subject2) << endl;
    cout << setw (columnwidth) << "Subject 3" << setw (columnwidth) << convertGrade(subject3) << endl;

}

char convertGrade(double subject){
    char letter;
    if (subject >= 8.0)
    {
        letter = 'A';
       }
       else if (subject >= 6.5 && subject < 8.0){
        letter = 'B';
       }
       else if (subject >= 5.5 && subject < 6.5){
        letter = 'C';
       }
       else if (subject >= 5.0 && subject < 5.5){
        letter = 'D';
       } 
       else {
        letter = 'F';
    }
    return letter;
}

double calcAverage(int size, double total){
    double averageGrade;
    averageGrade = total/size;
    return averageGrade;
}

void printData(string_view studentName, string_view studentLastName, double subject1, double subject2, double subject3, double average){

    cout << "Printing your results in a text file: Evaluation101.exe..." << endl;
    
    int columnwidth (30);
    
    fstream output;
    
    output.open ("Evaluation101.exe", std::fstream::in | std::fstream::out | std::fstream::app);
    output << "Name: " << studentLastName <<" "<< studentName << endl;
    output << "Here is the evaluation of student: " << studentLastName << " " << studentName << endl;

    output << left;
    output << setfill ('.');
    output << setw (columnwidth) << "Subject" << setw (columnwidth) << "Grade" <<endl;
    output << setw (columnwidth) << "Subject 1"  << setw (columnwidth) << subject1 << endl;
    output << setw (columnwidth) << "Subject 2" << setw (columnwidth) << subject2 << endl;
    output << setw (columnwidth) << "Subject 3" << setw (columnwidth) << subject3 << endl;

    output << "The average off all grades: " << setprecision(1) << fixed << average << endl;
    output << "And the lettergrade is: " << convertGrade(average)<< endl;
    output.close();
}
