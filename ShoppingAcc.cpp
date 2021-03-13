#include "ShoppingAcc.h"
#include <iterator>
shoppingAcc::shoppingAcc(string s, float b, set<Sale> ss):Account(s,b),sales(ss){}
shoppingAcc::~shoppingAcc(){}

void shoppingAcc::print(ostream & dev)const
{
	dev<<"The "<<bankName<<" shopping account has a balance of "<<balance<<" and the following sales:"<<endl;
	set<Sale>::iterator itr;
	for(itr=sales.begin();itr!=sales.end();++itr)
		dev<<(*itr);
}
void shoppingAcc::estimation()
{
	cout<<bankName<<" shopping account's sales estimation after 1 year is: "<<endl;
	set<Sale>::iterator itr;
	set<Sale> aux;
	Sale s;
		for(itr=sales.begin();itr!=sales.end();++itr)
			{
				s=(*itr);
				s.saleUpdate();
				aux.insert(s);
			}
	for(itr=aux.begin();itr!=aux.end();++itr)
		cout<<(*itr);
} 
void shoppingAcc::addMoney(float money)
{
	Account::addMoney(money);
	cout<<bankName<<" shopping account's new balance is "<<balance<<endl;
}
bool shoppingAcc::withdraw(float money)
{
	if(balance-money<0)
	{
		cout<<"Not enough funds"<<endl;
		return false;
	}
	else
	{
		balance-=money;
		cout<<bankName<<" shopping account's new balance is "<<balance<<endl;
	}
	return true;
}
void shoppingAcc::transfer(Account & a,float f)
{
	if(this!=&a)
	{
		cout<<"Transfer of "<<f<<" from "<<a.getName()<<" account to "<<bankName<<endl;
		if(a.withdraw(f))
			addMoney(f);
	}
	else cout<<"It is the same account"<<endl;
}
ostream & operator<<(ostream & out, const shoppingAcc & s)
{
	s.print(out);
	return out;
}
string shoppingAcc::getName()const{
	return bankName; }
