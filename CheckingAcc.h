#pragma once
#include "Account.h"

class checkingAcc:public Account{
	
	int fee;
	public:
		checkingAcc(string, float, int);
		~checkingAcc(){};
		void print(ostream&)const;
		void addMoney(float);
		void transfer(Account &,float);
		void estimation();
		bool withdraw(float);
		string getName()const;
		friend ostream & operator<<(ostream &, const checkingAcc &);
		
};
