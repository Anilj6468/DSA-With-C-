#include <iostream>
using namespace std;
class BankAccount {
protected:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string accNo, double bal) {
        accountHolderName = name;
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    void displayAccountInfo() {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingAccount(string name, string accNo, double bal, double rate)
        : BankAccount(name, accNo, bal) {
        interestRate = rate;
    }

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        cout << "Saving Account Interest: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string name, string accNo, double bal, double limit)
        : BankAccount(name, accNo, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn (with overdraft): " << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void checkOverDraft() {
        if (balance < 0) {
            cout << "Account is in overdraft!" << endl;
        } else {
            cout << "No overdraft used." << endl;
        }
    }
};


class FixedDepositAccount : public BankAccount {
private:
    int term;
    double interestRate;

public:
    FixedDepositAccount(string name, string accNo, double bal, int t, double rate)
        : BankAccount(name, accNo, bal) {
        term = t;
        interestRate = rate;
    }

    void calculateInterest() {
        double interest = (balance * interestRate * term) / (12 * 100);
        cout << "Fixed Deposit Interest: " << interest << endl;
    }
};

int main() {
    SavingAccount sa("Rahul", "SA123", 10000, 5);
    sa.displayAccountInfo();
    sa.deposit(2000);
    sa.calculateInterest();

    
    CheckingAccount ca("Amit", "CA456", 5000, 2000);
    ca.displayAccountInfo();
    ca.withdraw(6000); 
    ca.checkOverDraft();

    FixedDepositAccount fda("Neha", "FD789", 20000, 12, 6);
    fda.displayAccountInfo();
    fda.calculateInterest();

    return 0;
}