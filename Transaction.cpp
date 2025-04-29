#include "Transaction.h"

Transaction::Transaction() : date(""), amount(0.0), type("expense"), category("") {}

Transaction::Transaction(const std::string& d, double a, const std::string& t, const std::string& c)
    : date(d), amount(a), type(t), category(c) {}

void Transaction::setDate(const std::string& d) {
    date = d;
}

void Transaction::setAmount(double a) {
    amount = a;
}

void Transaction::setType(const std::string& t) {
    type = t;
}

void Transaction::setCategory(const std::string& c) {
    category = c;
}

std::string Transaction::getDate() const {
    return date;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getType() const {
    return type;
}

std::string Transaction::getCategory() const {
    return category;
}
