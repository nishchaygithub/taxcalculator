#include <iostream>
#include <string>
using namespace std;

enum categoryfortax
{
    GovtEmployee,
    Scientist,
    OfficeClerk,
    NormalPerson
};

// Function for Govt Employees
double calculateTax(double income, char G, int dummy1 = 0, float dummy2 = 2.1)
{
    if (G == 'G' && dummy1 == 0 && dummy2 == 2.1)
        return income * 0.15; // tax = 15%
    return 0.0;
}

// Function  tax for Scientists
double calculateTax(double income, char S, char c, int dummy)
{
    if (S == 'S' && c == 'c')
        return income * 0.12; // tax = 12%
    return 0.0;
}

// Function  tax for Office Clerks
double calculateTax(double income, char O, int dummy1, int dummy2)
{
    if (O == 'O')
        return income * 0.10; // tax = 10%
    return 0.0;
}

// Function  tax for Normal Persons
double calculateTax(double income, char N, int a, char dummy)
{
    if (N == 'N' && a == 69)
        return income * 0.20; // tax = 20%
    return 0.0;
}

// Function to clear the screen by printing newline characters
void clearScreen()
{
    cout << string(100, '\n');
}
void display()
{
    cout << "\n--------------------------------------------" << endl;
    cout << "   Tax Ranges (Tax as a percentage of income)" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Govt Employee: 15%" << endl;
    cout << "Scientist: 12%" << endl;
    cout << "Office Clerk: 10%" << endl;
    cout << "Normal Citizen: 20%" << endl;
    cout << "--------------------------------------------\n"
         << endl;
}
int main()
{
    cout << "\t -------------------------------------------" << endl;
    cout << "\t|         Universal Tax-Calculator         |" << endl;
    cout << "\t -------------------------------------------" << endl;

    char category;
    char choice;

    do
    {
        void display();
        cout << "\nTax Category" << endl;
        cout << "G. Govt Employee" << endl;
        cout << "S. Scientist" << endl;
        cout << "O. Office Clerks" << endl;
        cout << "N. Normal Citizen" << endl;
        cout << "Enter your category (G/S/O/N): ";
        cin >> category;
        if (category != 'G' && category != 'g' && category != 'S' && category != 's' && category != 'O' && category != 'o' && category != 'N' && category != 'n')
        {
            cout << "Invalid category selected." << endl;
            continue;
        }
        char *name;
        name = new char[50];
        cout << "Enter your name: ";
        cin.ignore();
        cin.getline(name, 50);

        double income;
        cout << "Enter your income: ";
        cin >> income;

        double tax = 0.0;

        switch (category)
        {

        case 'G':
            tax = calculateTax(income, category, 0, ' ');
            break;
        case 'S':
            tax = calculateTax(income, category, 'c', 0);
            break;
        case 'O':
            tax = calculateTax(income, category, 0, 0);
            break;
        case 'N':
            tax = calculateTax(income, category, 69, ' ');
            break;
        default:
            break;
        }

        clearScreen();

        cout << "\n\t   Tax Details for " << name << ":" << endl;
        cout << "\t -------------------------------------------" << endl;
        cout << "\t Tax Category: ";
        switch (category)
        {
        case 'G':
            cout << "Govt Employee" << endl;
            break;
        case 'S':
            cout << "Scientist" << endl;
            break;
        case 'O':
            cout << "Office Clerk" << endl;
            break;
        case 'N':
            cout << "Normal Citizen" << endl;
            break;
        }
        cout << "\t Income: Rs. " << income << endl;
        cout << "\t Tax to be paid: Rs. " << tax << endl;
        cout << "\t -------------------------------------------" << endl;

        delete[] name;
        cout << "Do you want to calculate tax for another person? (Y/N): ";
        cin >> choice;
        clearScreen();

    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting the program. Goodbye!" << endl;

    return 0;
}
