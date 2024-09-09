#include<bits/stdc++.h>
using namespace std;
int main() 
{
	string str,s="";
	cin>>str;
	stack<char> q;
	int i=0;
	while(i<str.size()) 
	{
		if(isalpha(str[i]))
		{
			q.push(str[i]);
		}
		else {
			q.pop();
		}
		i+=1;
	} 
	while(!q.empty()) {
		s+=q.top();
		q.pop();
	}
//	cout<<s<<endl;
	i=0;
	int j=s.size()-1;
	while(i<j) 
	{
		swap(s[i],s[j]);
		i+=1;
		j-=1;
	}
	cout<<s<<endl;
}