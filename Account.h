#pragma once
#include <string>
#include <iostream>
using namespace std;

class Account{
	
	protected:
		string bankName;
		float balance;
	public:
		Account();
		Account(string, float);
		virtual ~Account();
		virtual void print(ostream&) const=0;
		virtual void addMoney(float)=0;
		virtual void transfer(Account&,float)=0;
		virtual void estimation()=0;
		virtual bool withdraw(float)=0;
		virtual string getName()const=0;
		friend ostream & operator<<(ostream &, const Account &);
};

