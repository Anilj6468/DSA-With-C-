#include <iostream>
using namespace std;

// Base Class
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    void displayDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived Class
class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor
    SavingAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    // Method to calculate interest
    void calculateInterest() {
        double interest = (balance * interestRate) / 100;
        cout << "Interest: " << interest << endl;
    }
};

int main() {
    SavingAccount acc1(101, "John Doe", 5000, 5);

    acc1.displayDetails();
    acc1.calculateInterest();

    return 0;
}