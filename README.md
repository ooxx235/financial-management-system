#include <iostream>
#include <string>
#include "FinanceManager.h"
#include "Transaction.h"

int main() {
    FinanceManager manager;

    int choice;
    do {
        std::cout << "\n===== Personal Finance Management =====\n";
        std::cout << "Add Transaction\n Enter 1";
        std::cout << "View Transactions\n Enter 2";
        std::cout << "Generate Report\n Enter 3";
        std::cout << "Exit\n Enter 4";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // 輸入交易資料
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

                // 創建 Transaction 物件並加入
                Transaction transaction(date, amount, type, category);
                manager.addTransaction(transaction);
                std::cout << "Transaction added successfully.\n";
                break;
            }
            case 2:
                // 顯示所有交易
                manager.viewTransactions();
                break;
            case 3:
                // 顯示報告
                manager.generateReport();
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}