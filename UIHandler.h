#ifndef UIHANDLER_H
#define UIHANDLER_H

#include "FinanceManager.h"
#include <iostream>
#include <string>

class UIHandler {
private:
    FinanceManager& manager;

public:
    UIHandler(FinanceManager& manager);
    void run();
private:
    void displayMenu() const;
    void addTransaction();
    void viewTransactions() const;
    void generateReport() const;
};

#endif
