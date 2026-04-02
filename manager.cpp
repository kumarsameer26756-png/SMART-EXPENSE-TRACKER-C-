#include <iostream>
#include <fstream>
#include <string>
#include "task.h"

using namespace std;

void ExpenseManager::addExpense(Expense e) {
    ofstream outFile(filename, ios::app); // Open in append mode
    if (outFile.is_open()) {
        outFile << e.date << "," << e.category << "," << e.amount << endl;
        outFile.close();
        cout << "Successfully saved!\n";
    } else {
        cout << "Error opening file!\n";
    }
}

void ExpenseManager::showTotal() {
    ifstream inFile(filename);
    string line, date, cat;
    double amt, total = 0;

    if (!inFile) {
        cout << "No data found.\n";
        return;
    }

    cout << "\n--- Your Expenses ---\n";
    // Reading CSV format: Date,Category,Amount
    while (getline(inFile, line)) {
        // Simple logic to find commas and extract data
        size_t firstComma = line.find(',');
        size_t lastComma = line.find_last_of(',');
        
        amt = stod(line.substr(lastComma + 1));
        total += amt;
        cout << line << endl;
    }
    cout << "---------------------\n";
    cout << "Total Spending: " << total << endl;
    inFile.close();
}