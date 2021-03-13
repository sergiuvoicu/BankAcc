#include "SavingsAcc.h"

savingsAcc::savingsAcc(string s, float b, float c, float l):Account(s,b),comission(c),limit(l){}
savingsAcc::~savingsAcc(){}

void savingsAcc::print(ostream & dev)const
{
	dev<<"The "<<bankName<<" savings account has a balance of "<<balance<<" a comission of "<<comission<<"% and a limit of "<<limit<<endl;
}
void savingsAcc::addMoney(float money)
{
	Account::addMoney(money);
	cout<<bankName<<" savings account's new balance is "<<balance<<endl;
}
void savingsAcc::estimation()
{
	float est=balance;
	
	for(int i=0;i<12;i++)
		est+=est*comission;
		
	cout<<bankName<<" savings account's balance estimation after 1 year is "<<est<<endl;
}
bool savingsAcc::withdraw(float money)
{
	if(balance-money<0)
	{
		cout<<"Not enough funds"<<endl;
		return false;
	}
	else if(money>limit)
	{
		cout<<"Sum exceeds account limit"<<endl;
		return false;
	}
	else
	{
		balance-=money;
		cout<<bankName<<" savings account's new balance is "<<balance<<endl;
	}
	return true;
}
void savingsAcc::transfer(Account & a,float f)
{
	if(this!=&a)
	{
		cout<<"Transfer of "<<f<<" from "<<a.getName()<<" account to "<<bankName<<endl;
		if(a.withdraw(f))
			addMoney(f);
	}
	else cout<<"It is the same account"<<endl;
}
ostream & operator<<(ostream & out, const savingsAcc & sa)
{
	sa.print(out);
	return out;
}

string savingsAcc::getName()const{
	return bankName; }
