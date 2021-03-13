#include "Client.h"
#include <iterator>
Client::Client(string s, map<int,Account*> MA):name(s),Accs(MA){};

ostream & operator<<(ostream & dev, Client & c)
{
	dev<<c.name<<" owns the following accounts: "<<endl;
	map<int,Account*>::iterator itr;
	for(itr=c.Accs.begin();itr!=c.Accs.end();++itr)
		dev<<endl<<*(itr->second);
	return dev;
}
void Client::ATM()
{
	char x('Y'),y('Y');
	int nr;
	int key;
	float money;
	map<int,Account*>::iterator itr;
	
	
	do
	{
		for(itr=Accs.begin();itr!=Accs.end();++itr)
			cout<<itr->first<<"\t"<<*(itr->second);
			
		cout<<"Which account would you like to enter, Mr/Mrs "<<name<<"?"<<endl;
		cin>>nr;
		itr=Accs.find(nr);
		do
		{
			cout<<"Press 1 to add money "<<endl<<"Press 2 to withdraw money "<<endl<<"Press 3 to transfer money from another account "<<endl<<"Press 4 to view a 1-year estimation about the account"<<endl;
			cin>>key;
			switch(key)
			{
				case 1:
					{
						cout<<"Insert the amount"<<endl;
						cin>>money;
						itr->second->addMoney(money);
						break;
					}
				case 2:
					{
						cout<<"Insert the amount"<<endl;
						cin>>money;
						itr->second->withdraw(money);
						break;
					}
				case 3:
					{
						int find;
						cout<<"Insert the number of another account and the amount wanted"<<endl;
						cin>>find;
						cin>>money;
						
						map<int,Account*>::iterator it;
						it=Accs.find(find);
						itr->second->transfer(*(it->second),money);
						break;
					}
				case 4:
					{
						itr->second->estimation();
						break;
					}
				default:
					{
						cout<<"You have pressed a wrong number, try again"<<endl;
						break;
					}
			}
			
			cout<<"Would you like to do another operation? "<<endl<<"\t Press Y if you do, or any other key if you don't"<<endl;
			cin>>x;
		}while(x=='Y');
		
		cout<<"Would you like to enter another account?"<<endl<<"\t Press Y if you do, or any other key if you don't"<<endl;
		cin>>y;
	}while(y=='Y');
}
