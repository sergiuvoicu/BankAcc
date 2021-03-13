#pragma once
#include "Account.h"
#include <map>

class Client{
	string name;
	map<int,Account*> Accs;
	public:
		Client(string, map<int,Account*>);
		void ATM();
		friend ostream & operator<<(ostream &, Client &);
};

