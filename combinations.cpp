#include<bits/stdc++.h>
using namespace std;
void recursion(vector<int>v1,int tar,int index,int size,int sum,vector<int>ans)
{
	if(index>=size and sum!=tar) return ;
	else if(sum==tar)
	{	  
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<endl;
		return;    
	}
	else if(sum>tar) return;
	ans.push_back(v1[index]);
	recursion(v1,tar,index,size,sum+v1[index],ans);
	ans.pop_back();
	recursion(v1,tar,index+1,size,sum,ans);
}
int main()
{
	int n;
	cin>>n;
	vector<int>v1;
	for(int i=0;i<n;i++) {
		int val;
		cin>>val;
		v1.push_back(val);
	}
	int tar;
	cin>>tar;
	vector<int>ans;
	sort(v1.begin(),v1.end());
	recursion(v1,tar,0,v1.size(),0,ans);
}
