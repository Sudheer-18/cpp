#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin>>nums[i];
    vector<int> dp(n,1);
    int maxi = 0;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) dp[i] = max(dp[i],dp[j]+1);
        }
        maxi = max(maxi,dp[i]);
    }
    cout<<maxi<<endl;
}