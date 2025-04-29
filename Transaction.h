#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string date;
    double amount;
    std::string type;     // "income" or "expense"
    std::string category;

public:
    Transaction();
    Transaction(const std::string& date, double amount, const std::string& type, const std::string& category);

    void setDate(const std::string& d);
    void setAmount(double a);
    void setType(const std::string& t);
    void setCategory(const std::string& c);

    std::string getDate() const;
    double getAmount() const;
    std::string getType() const;
    std::string getCategory() const;
};

#endif
