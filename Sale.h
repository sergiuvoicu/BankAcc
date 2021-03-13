#pragma once
#include <string>
#include <iostream>
using namespace std;

class Sale{
	string compName;
	double percent;
	double decrease;
	
	public:
		Sale();
		Sale(string, double, double);
		void saleUpdate();
		friend ostream & operator<<(ostream &, const Sale &);
		friend bool operator<(const Sale &, const Sale &);
		
};
