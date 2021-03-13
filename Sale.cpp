#include "Sale.h"
Sale::Sale(){};
Sale::Sale(string s, double p, double d):compName(s),percent(p),decrease(d){}

ostream & operator<<(ostream & dev, const Sale & s)
{
	dev<<"\t \t"<<s.compName<<" offers a sale of "<<s.percent<<"% and a monthly decrease of "<<s.decrease<<"%"<<endl;
	return dev;
}
void Sale::saleUpdate()
{
	for(int i=0;i<12;i++)
	percent-=decrease;
}
bool operator<(const Sale & x, const Sale & y){
	return (x.percent>y.percent); }

