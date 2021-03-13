#pragma once
#include "Account.h"

class savingsAcc:public Account{
	
	float comission;
	float limit;
	
	public:
		savingsAcc(string, float , float, float);
		~savingsAcc();
		void print(ostream &)const;
		void addMoney(float);
		void transfer(Account&,float);
		void estimation();
		bool withdraw(float);
		string getName()const;
		friend ostream & operator<<(ostream &, const savingsAcc &);
		
		
		
};
