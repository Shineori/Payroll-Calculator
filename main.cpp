#include <iostream>
using namespace std;

const double state = 0.06; // Started with int but had to use double because of decimal values// --State Tax Rate--
const double fed = 0.12; // --Federal Tax Rate--
const double uniFee = 0.02; // --Union Fee Rate--
const double otm = 1.5; // --Overtime Multiplier--
const int maxEmp = 100; // --Maximum Number of Employees--

struct Employees {
    string firstName;
    string middleName;
    string lastName;
    int hr;
    float hw;
    float gi;
    float otp;
    int st;
    int fedTax;
    int uniFee;
    int netInc; 
};

int main() {
    Employees emp;
    
    cout << "Enter Employee's First Name: ";
    cin >> emp.firstName;
    cout << "Enter Employee's Middle Name: ";
    cin >> emp.middleName;
    cout << "Enter Employee's Last Name: ";
    cin >> emp.lastName;
    cout << "Enter Employee's Hourly Rate: ";
    cin >> emp.hw;
    cout << "Enter Employee's Hours Worked: ";
    cin >> emp.hr;
    
    emp.gi = emp.hw * emp.hr;
    if (emp.hr > 40) { // --Creating an Overtime Checker--
        emp.otp = (emp.hr - 40) * emp.hw * otm;
    } else {
        emp.otp = 0;
    }

    emp.st = emp.gi * state;
    emp.fedTax = emp.gi * fed;
    emp.uniFee = emp.gi * uniFee;
    emp.netInc = emp.gi - emp.st - emp.fedTax - emp.uniFee;

    cout << "\nEmployee Information:\n";
    cout << "Name: " << emp.firstName << " " << emp.middleName << " " << emp.lastName << endl;
    cout << "Hourly Rate: $" << emp.hw << endl;
    cout << "Hours Worked: " << emp.hr << endl;
    cout << "Gross Income: $" << emp.gi << endl;
    cout << "Overtime Pay: $" << emp.otp << endl;
    cout << "State Tax: $" << emp.st << endl;
    cout << "Federal Tax: $" << emp.fedTax << endl;
    cout << "Union Fee: $" << emp.uniFee << endl;
    cout << "Net Income: $" << emp.netInc << endl;
    cout << "\n";

    system("pause"); // --Pauses the program so the user can see the output--

    return 0;
}