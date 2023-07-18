#include <iostream>
using namespace std;

enum categoryfortax
{
    GovtEmployee,
    Scientist,
    OfficeClerk,
    NormalPerson
};

class TaxCalculator
{
private:
    double TaxForGovtEmployee(double income)
    {
        return income * 0.15; // tax = 15%
    }

    double TaxForScientists(double income)
    {
        return income * 0.12; // tax = 12%
    }

    double TaxForClerk(double income)
    {
        return income * 0.10; // tax = 10%
    }

    double TaxForNormalPerson(double income)
    {
        return income * 0.20; // tax = 20%
    }

public:
    double calculateTax(categoryfortax category, double income)
    {
        switch (category)
        {
        case GovtEmployee:
            return TaxForGovtEmployee(income);
        case Scientist:
            return TaxForScientists(income);
        case OfficeClerk:
            return TaxForClerk(income);
        case NormalPerson:
            return TaxForNormalPerson(income);
        default:
            cout << "Invalid tax category." << endl;
            return 0;
        }
    }
};
void clearScreen()
{
    cout << string(100, '\n');
}


int main()
{
    cout << endl
         << "\t -------------------------------------------------" << endl
         << "\t|      Universal Tax-Calculator [PvT.LTD]         |\n"
         << "\t -------------------------------------------------" << endl;

    TaxCalculator taxCalculator;

    int category = -1;

    char choice;

    do
    {
        cout << "Tax Category" << endl
             << "0. Govt Employee" << endl
             << "1. Scientist" << endl
             << "2. Office Clerks" << endl
             << "3. Normal Citizen" << endl;
        cout << "Enter your category (0 to 3) : ";
        cin >> category;

        if (category < 0 || category > 3)
        {
            cout << "Invalid category selected." << endl;
            continue;
        }

        string name;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        double income;
        cout << "Enter your income: ";
        cin >> income;

        double tax = taxCalculator.calculateTax(categoryfortax(category), income);

        clearScreen();

        cout << "\nTax Details for " << name << ":" << endl;
        cout << "--------------------------" << endl;
        cout << "Tax Category: ";
        switch (category)
        {
        case GovtEmployee:
            cout << "Govt Employee" << endl;
            break;
        case Scientist:
            cout << "Scientist" << endl;
            break;
        case OfficeClerk:
            cout << "Office Clerk" << endl;
            break;
        case NormalPerson:
            cout << "Normal Citizen" << endl;
            break;
        }
        cout << "Income: Rs. " << income << endl;
        cout << "Tax to be paid: Rs. " << tax << endl;
        cout << "--------------------------" << endl;

        cout << "Do you want to calculate tax for another person? (Y/N): ";
        cin >> choice;
        clearScreen();

    } while (choice == 'Y' || choice == 'y');

    cout << "Exiting the program. Goodbye!" << endl;

    return 0;
}
