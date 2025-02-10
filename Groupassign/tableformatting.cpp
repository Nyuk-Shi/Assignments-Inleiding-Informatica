#include <iostream>
#include <ios>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

int main (){
    string familienaam,voornaam, IDnummer;
    
    cout << "Vul uw familienaam in: " <<endl;
    cin >> familienaam ;
    cout << "Vul uw voornaam in: " <<endl;
    cin >> voornaam;
    cout << "Vul uw IDnummer in: " <<endl;
    cin >> IDnummer;
    cout << "Uw naam is: "<< familienaam <<" "<< voornaam <<endl;
    cout << "Uw id nummer is: "<< IDnummer <<endl;
    
    float SUB1;
    float SUB2;
    float SUB3;
    float SUB4;
    float SUB5;
    float Average;
    float Percentage;
    
    cout << "Please enter your grade for Liniar algebra1: " << endl;
    cin >> SUB1;
    cout << "Please enter your grade for Electrical Circuits: " << endl;
    cin >> SUB2;
    cout << "Please enter your grade for Calculus 1: " << endl;
    cin >> SUB3;
    cout << "Please enter your grade for ETM 1: " << endl;
    cin >> SUB4;
    cout << "Please enter your grade for EV: " << endl;
    cin >> SUB5;
     
    Average = ((SUB1 + SUB2 + SUB3 + SUB4 + SUB5)/5);
    Percentage = ((Average/10)*100);
    
    cout << "Here is the evaluation of student: " << familienaam<<" "<<voornaam << endl;
    cout << "The average off all grades: " <<Average << endl;
    cout << "Average in percentages: " << Percentage << "%" << endl;
    
    string grade;
    string message;
    
    if (Percentage >= 80){
     grade = ("Grade: A");
     message = ("Okay NERD!!!");
     //cout << "Grade A" << endl;
     //cout << "Okay NERD!!!" << endl;
     cout << grade << endl;
     cout << message << endl;
    }
    
    else if (Percentage >=65 && Percentage <80){
     grade = ("Grade: B");
     message = ("You can do better than that");
     //cout << "Grade  B" << endl;
     //cout << "You can do better than that" << endl;
     cout << grade << endl;
     cout << message << endl;
    }
    
    else if (Percentage >= 55 && Percentage <65){
     grade = ("Grade: C");
     message = ("Oof, try harder");
     //cout << "Grade C" << endl; 
    // cout << "Oof, try harder" << endl;
     cout << grade << endl;
     cout << message << endl;
    }
    
    else if (Percentage >= 50 && Percentage <55){
     grade = ("Grade: D");
     message = ("Congrats? At least you aren't dumb ig");
     //cout << "Grade D" << endl; 
     //cout << "Congrats? At least you aren't dumb ig" << endl;
     cout << grade << endl;
     cout << message << endl;
    }
    
    else if (Percentage <50){
     grade = ("Grade: F");
     message = ("Womp womp, beter luck next time");
     //cout << "Grade F" << endl; 
     //cout << "Womp womp, beter luck next time" << endl;
     cout << grade << endl;
     cout << message << endl;
    }
    
    cout << "Printing your results in a text file: Evaluation101.exe..." << endl;
    //Start van de code om in een file te printen.
    
    int columnwidth (30);
    
    fstream output;
    
    output.open ("Evaluation101.exe", std::fstream::in | std::fstream::out | std::fstream::app);
    output << "Name: " << familienaam<<" "<< voornaam << endl;
    output << "Here is the evaluation of student: " << familienaam<<" "<<voornaam << endl;

    output << left;
    output << setfill ('.');
    output << setw (columnwidth) << "Subject" << setw (columnwidth) << "Grade" <<endl;
    output << setw (columnwidth) << "Linear Algebra 1"  << setw (columnwidth) << SUB1 << endl;
    output << setw (columnwidth) << "Electrical Circuits" << setw (columnwidth) << SUB2 << endl;
    output << setw (columnwidth) << "Calculus 1" << setw (columnwidth) << SUB3 << endl;
    output << setw (columnwidth) << "ETM 1" << setw (columnwidth) << SUB4 << endl;
    output << setw (columnwidth) << "EV" << setw (columnwidth) << SUB5 << endl;

    output << "The average off all grades: " << Average << endl;
    output << "Average in percentages: " << Percentage << "%" << endl;
    output << grade << endl;
    output << message << endl;
    output << " " << endl;
    output.close();
    

    return 0;
}
