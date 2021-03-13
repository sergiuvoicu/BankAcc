#include "CheckingAcc.h"

checkingAcc::checkingAcc(string s, float b, int f):Account(s,b),fee(f){}
void checkingAcc::print(ostream & dev)const 
{
	dev<<"The "<<bankName<<" checking account has a balance of "<< balance<<" and a fee of "<<fee<<endl;
}
ostream & operator<<(ostream & out, const checkingAcc & ca)
{
	ca.print(out);
	return out;
}
void checkingAcc::addMoney(float money)
{
	Account::addMoney(money);
	cout<<bankName<<" checking account's new balance is "<<balance<<endl;
}
void checkingAcc::estimation()
{
	float est=balance;
	for(int i=0;i<12;i++)
		est-=fee;
	if(est < 0)
		cout<<bankName<<" checking account has a debt of "<<est;
		
	else cout<<bankName<<" checking account's balance estimation after 1 year is "<<est<<endl;
}
bool checkingAcc::withdraw(float money)
{

	if(balance-money-fee<0)
	{
		cout<<"Not enough funds"<<endl;
		return false;
	}
	else
	{
		balance-=money;
		cout<<bankName<<" checking account's new balance is "<<balance<<endl;
	}
	return true;
}
void checkingAcc::transfer(Account & a,float f)
{
	if(this!=&a)
	{
		cout<<"Transfer of "<<f<<" from "<<a.getName()<<" account to "<<bankName<<endl;
		if(a.withdraw(f))
			addMoney(f);
	}
	else cout<<"It is the same account"<<endl;
}
string checkingAcc::getName()const{
	return bankName; }
