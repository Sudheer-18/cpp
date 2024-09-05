#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	stack<char>s1;
	int i=0;
	for(i=0;i<str.length();i++)
	{
		if(str[i]=='{' || str[i]=='(' || str[i]==']')
		{
			s1.push(str[i]);
		}
		else
		{
			if(str[i]==']') {
				if(!s1.empty() && s1.top()=='[')
				{
					s1.pop(); 
				}
				else {
					cout<<"Invalid";
					break;
					} 
				}
			else if(str[i]=='}')
				{
					if(!s1.empty() && s1.top()=='{')
					{
						s1.pop();
					}
					else {
						cout<<"Invalid";
						break;
					}
				}
			else 
			{
				cout<<"Invalid";
				break;
			}		
		}
		if(i==str.length() && !s1.empty()) cout<<"Valid";
	}
}
	