#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    
    ll sum = 0;

    for(int i=0; i<n; i++) {
        sum += v[i];
    }

    cout << max(sum, (ll)2*v[n-1]) << endl;

    return 0;
}