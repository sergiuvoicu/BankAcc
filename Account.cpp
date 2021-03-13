#include "Account.h"
Account::Account(){}
Account::Account(string s, float b):bankName(s),balance(b){}
Account::~Account(){}
void print(ostream& dev){}
ostream & operator<<(ostream & dev, const Account & a)
{
	a.print(dev);
	return dev;
}
void Account::addMoney(float money)
{
	balance+=money;
}
