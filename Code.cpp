// BANKING SYSTEM
// CREATED BY - MAYANK TYAGI
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define MIN_BALANCE 500

class Account
{
private:
	long accountNumber;
	string firstName;
	string lastName;
	float balance;
	static long NextAccountNumber;
public:
	Account(){}
	Account(string fname, string lname, float balance);
	long getAccNo(){return accountNumber;}
	string getFirstName(){return firstName;}
	string getLastName(){return lastName;}
	float getBalance(){return balance;}
	void Deposit(float amount);
	void Withdraw(float amount);
	static void setLastAccountNumber(long accountNumber);
	static long getLastAccountNumber();
	friend ofstream & operator<<(ofstream &ofs, Account &acc);
	friend ifstream & operator>>(ifstream &ifs, Account &acc);
	friend ostream & operator<<(ostream &os, Account &acc);

};
long Account::NextAccountNumber=0;

class Bank
{
private:
	map<long,Account> accounts;
public:
	Bank();
	Account OpenAccount(string fname, string lname, float balance);
	Account BalanceEnquiry(long accountNumber);
	Account Deposit(long accountNumber, float amount);
	Account Withdraw(long accountNumber, float amount);
	void CloseAccount(long accountNumber);
	void ShowAllAccount();
	~Bank();
};

