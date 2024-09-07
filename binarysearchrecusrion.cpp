#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>& v1, int i, int j, int k) {
    if (i >= j) {
        cout << "Element not found";
        return;
    }
    
    int mid = (i + j) / 2;
    
    if (v1[mid] == k) {
        cout << "Element found";
        return;
    } else if (v1[mid] > k) {
        fun(v1, i, mid, k);
    } else {
        fun(v1, mid + 1, j, k);
    } 
}

int main() {
    int n, k;
    cin >> n;
    vector<int> v1;

    for (int i = 0; i < n; i++) {
        cin >> k;
        v1.push_back(k);
    }

    int search;
    cin >> search;
    sort(v1.begin(), v1.end());
    fun(v1, 0, v1.size(), search);

    return 0;
}
