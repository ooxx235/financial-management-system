#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "Transaction.h"
#include <vector>
#include <string>

class FinanceManager {
private:
    std::vector<Transaction> transactions;

public:
    void addTransaction(const Transaction& t);
    void viewTransactions() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void generateReport() const;
};

#endif
