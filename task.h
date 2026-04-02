#include <string>

struct Expense {
    std::string date;
    std::string category;
    double amount;
    Expense(const std::string& d, const std::string& c, double a) : date(d), category(c), amount(a) {}
};

class ExpenseManager {
private:
    const std::string filename;
public:
    ExpenseManager() : filename("expense.csv") {}
    void addExpense(Expense e);
    void showTotal();
};