#include "UIHandler.h"

UIHandler::UIHandler(FinanceManager& manager) : manager(manager) {}

void UIHandler::run() {
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 4);
}

void UIHandler::displayMenu() const {
    std::cout << "\n===== Personal Finance Management =====\n";
    std::cout << " Enter 1:Add Transaction\n ";
    std::cout << "Enter 2:View Transactions\n ";
    std::cout << "Enter 3:Generate Report\n ";
    std::cout << "Enter 4:Exit\n ";
}

void UIHandler::addTransaction() {
    std::string date, type, category;
    double amount;

    std::cout << "Enter transaction date (YYYY-MM-DD): ";
    std::cin >> date;

    std::cout << "Enter amount: ";
    std::cin >> amount;

    std::cout << "Enter transaction type (income/expense): ";
    std::cin >> type;

    std::cout << "Enter category (e.g., Food, Salary, etc.): ";
    std::cin >> category;

    Transaction transaction(date, amount, type, category);
    manager.addTransaction(transaction);
    std::cout << "Transaction added successfully.\n";
}

void UIHandler::viewTransactions() const {
    manager.viewTransactions();
}

void UIHandler::generateReport() const {
    manager.generateReport();
}
