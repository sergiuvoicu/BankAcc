#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include "Sale.h"
#include "CheckingAcc.h"
#include "SavingsAcc.h"
#include "ShoppingAcc.h"
#include "Account.h"
#include "Client.h"

int main(int argc, char** argv) {
	
/*	Sale s1("5 To Go", 5,0.1), s2("Starbucks",10,0.2), s3("McDonald's",7,0.15);
	checkingAcc c1("BRD",1500,300);
	savingsAcc S1("BCR",2500,0.1,750);
	
	set<Sale> ss;
	ss.insert(s1);
	ss.insert(s2);
	ss.insert(s3);
	shoppingAcc sA1("ING", 2235,ss);
	c1.addMoney(1100);
	S1.withdraw(750);
	c1.transfer(S1,500);
	
	map<int,Account*> accs;
	accs[1]=&c1;
	accs[2]=&S1;
	accs[3]=&sA1;
	map<int,Account*>::iterator itr;
	itr=accs.begin();
	itr++;
	itr++;
	
	itr->second->transfer(c1,500);
	Client C1("John Smith",accs);
	cout<<C1;
	c1.estimation();
	Client C2("Alex Moore",accs);
	vector<Client> v;
	v.push_back(C1);
	v.push_back(C2);
	int n=v.size();
	for(int i=0;i<n;i++)
	cout<<v[i];*/
	
	vector<Client> v;
	string name;
	char X('Y');
	map<int,Account*> accs;
	
	do
	{
		
		cout<<"Enter client's name"<<endl;
		getline(cin,name);
		int type;
		
		int i=1;
		char k('Y');
		
		do{
			string bank;
			float balance;
			
			cout<<"Choose what type of account you want to insert"<<endl<<"\t Press 1 for a checking account"<<endl<<"\t Press 2 for a savings account"<<endl<<"\t Press 3 for a shopping account"<<endl;
			cin>>type;
			
			switch(type)
			{
			
			
				case 1:
					{
						int fee;
						
						cout<<"Insert the bank's name"<<endl;
						cin.ignore();
						getline(cin,bank);
						
						cout<<"Insert the balance"<<endl;
						cin>>balance;
						
						cout<<"Insert the fee"<<endl;
						cin>>fee;
						
						checkingAcc * c=new checkingAcc(bank, balance, fee);
						accs[i]=c;
						i++;
						
						break;
					}
					
				case 2:
					{
						float comission;
						float limit;
						
						cout<<"Insert the bank's name"<<endl;
						cin.ignore();
						getline(cin,bank);
						
						cout<<"Insert the balance"<<endl;
						cin>>balance;
						
						cout<<"Insert the monthly comission"<<endl;
						cin>>comission;
						
						cout<<"Insert account's withdraw limit"<<endl;
						cin>>limit;
						
						savingsAcc * s=new savingsAcc(bank,balance,comission,limit);
						accs[i]=s;
						i++;
						
						break;
					}
					
				case 3:
					{
						double percent;
						double decrease;
						char j('Y');
						set<Sale> ss;
						string company;
						
						cout<<"Insert the bank's name"<<endl;
						cin.ignore();
						getline(cin,bank);
						
						cout<<"Insert the balance"<<endl;
						cin>>balance;
						
						do
						{
							cout<<"Insert the company"<<endl;
							cin.ignore();
							getline(cin,company);
							
							cout<<"Insert the sale percent"<<endl;
							cin>>percent;
							
							cout<<"Insert the monthly decrease"<<endl;
							cin>>decrease;
							
							Sale s(company,percent,decrease);
							ss.insert(s);
							
							cout<<"\t Press Y if you want to insert another company, or any other key if you don't want to"<<endl;
							cin>>j;
							
						}while(j=='Y');
						
						shoppingAcc *sa= new shoppingAcc(bank, balance, ss);
						accs[i]=sa;
						i++;
						break;
					}
				default:
					{
						cout<<"You have introduced a wrong number, try again"<<endl;
						break;
					}
				}
		
			cout<<"Do you want to insert another account for "<<name<<"?"<<endl<<"\t Press Y if you want to insert another account, or any other key if you don't want to"<<endl;
			cin>>k;
		}while(k=='Y');
		
		Client c1(name,accs);
		v.push_back(c1);
		
		cout<<"Do you want to insert another client?"<<endl<<"\t Press Y if you want to, or any other key if you don't"<<endl;;
		cin>>X;
		accs.clear();
		cin.ignore();
	}while(X=='Y');
	
	vector<Client>::iterator itr;
	for(itr=v.begin();itr!=v.end();++itr)
		itr->ATM();
	return 0;
}
