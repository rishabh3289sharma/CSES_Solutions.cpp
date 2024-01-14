#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    ll n, x;
    cin >> n >> x;

    vector<ll> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    } 

    map<ll, int> mp;
    ll sum = 0;
    ll ans = 0;

    for(int i=0; i<n; i++) {
         
         sum += v[i];

         if(sum == x) ans++;

         if(mp.find(sum-x) != mp.end()) {
            ans += mp[sum-x];
         }

         mp[sum]++;

    }
   
    cout << ans << endl;

    return 0;
}