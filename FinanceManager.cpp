#include "FinanceManager.h"

#include <iostream>

#include <fstream>

#include <sstream>



using namespace std;



void FinanceManager::addTransaction(const Transaction& t) {

    transactions.push_back(t);

}



void FinanceManager::viewTransactions() const {

    for (size_t i = 0; i < transactions.size(); ++i) {

        const Transaction& t = transactions[i];

        cout << "Date: " << t.getDate()

             << ", Amount: " << t.getAmount()

             << ", Type: " << t.getType()

             << ", Category: " << t.getCategory() << endl;

    }

}



void FinanceManager::saveToFile(const string& filename) const {

    ofstream outFile(filename.c_str());  // 使用 c_str() 將 string 轉換為 const char*

    if (!outFile) {

        cerr << "Failed to open file for writing." << endl;

        return;

    }



    for (size_t i = 0; i < transactions.size(); ++i) {

        const Transaction& t = transactions[i];

        outFile << t.getDate() << ","

                << t.getAmount() << ","

                << t.getType() << ","

                << t.getCategory() << endl;

    }



    outFile.close();

}



void FinanceManager::loadFromFile(const string& filename) {

    ifstream inFile(filename.c_str());  // 使用 c_str() 將 string 轉換為 const char*

    if (!inFile) {

        cerr << "Failed to open file for reading." << endl;

        return;

    }



    transactions.clear();

    string line;

    while (getline(inFile, line)) {

        stringstream ss(line);

        string date, type, category, amountStr;

        double amount;



        // 解析每一行的CSV格式

        if (getline(ss, date, ',') &&

            getline(ss, amountStr, ',') &&

            getline(ss, type, ',') &&

            getline(ss, category, ',')) {

            // 使用 stringstream 將字串轉換為 double，避免使用 stod

            stringstream(amountStr) >> amount;

            Transaction t(date, amount, type, category);

            transactions.push_back(t);

        }

    }

    inFile.close();

}



void FinanceManager::generateReport() const {

    double totalIncome = 0.0, totalExpense = 0.0;



    for (size_t i = 0; i < transactions.size(); ++i) {

        const Transaction& t = transactions[i];

        if (t.getType() == "income") {

            totalIncome += t.getAmount();

        } else if (t.getType() == "expense") {

            totalExpense += t.getAmount();

        }

    }



    cout << "Total Income: " << totalIncome << endl;

    cout << "Total Expense: " << totalExpense << endl;

    cout << "Net Savings: " << (totalIncome - totalExpense) << endl;

}

