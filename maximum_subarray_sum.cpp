#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
   
    ll n;
    cin >> n;

    vector<ll> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    ll curr = v[0];
    ll ans = v[0];

    for(int i=1; i<n; i++) {

         curr = max(v[i], v[i]+curr);

         ans = max(ans, curr);

    }

    cout << ans << endl;

    return 0;
}