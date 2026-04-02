#include <iostream>
#include <string>
#include "task.h"

using namespace std;

int main() {
    ExpenseManager manager;
    int choice;

    do {
        cout << "\n1. Add Expense\n2. View All & Total\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string d, c;
            double a;
            cout << "Enter Date (DD-MM-YYYY): "; cin >> d;
            cout << "Enter Category: "; cin >> c;
            cout << "Enter Amount: "; cin >> a;

            Expense newExpense(d, c, a);
            manager.addExpense(newExpense);
        } 
        else if (choice == 2) {
            manager.showTotal();
        }
    } while (choice != 3);

    return 0;
}