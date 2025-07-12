#include<bits/stdc++.h>
#define ll long long
using namespace std;

class BIT{
    vector<ll> Tree;
    ll n;
    public:
        BIT(ll size) {
            n = size;
            Tree.resize(n+1,0);
        }
        void update(ll i,ll val) {
            while(i <= n) {
                Tree[i] += val;
                i += (i & -i);  
            }
        }
        ll Query(ll i) {
            int sum = 0;
            while(i > 0) {
                sum += Tree[i];
                i -= (i & -i);
            }
            return sum;
        }
        ll RangeSum(ll l, ll r) {
            return Query(r) - Query(l-1);
        }
};


int main() {

    ll N;
    cin>>N;
    vector<ll> V(N);
    for(ll i=0; i<N; i++) cin>>V[i];

    BIT bit(N);

    for(ll i=1; i<=N; i++) {
        bit.update(i,V[i]);
    }

    ll NQ;
    while(NQ--) {
        ll start , end;
        cin>>start>>end;
    }
    
}