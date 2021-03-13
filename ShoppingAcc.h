#pragma once
#include "Account.h"
#include "Sale.h"
#include <set>

class shoppingAcc:public Account{
	
	set<Sale> sales;
	
	public:
		shoppingAcc(string, float, set<Sale>);
		~shoppingAcc();
		void print(ostream &)const;
		void addMoney(float);
		void transfer(Account &, float);
		void estimation();
		bool withdraw(float);
		string getName()const;
		friend ostream & operator<<(ostream &, const shoppingAcc &);
		
		
};
