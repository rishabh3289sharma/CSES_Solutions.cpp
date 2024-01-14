#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    int n;
    cin >> n;

    vector<ll> v(n+1);

    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    map<ll, ll> mp;

    ll ans = 0;

    ll i=1;
    ll j=1; 

    while(j <= n) {
        
        if(mp[v[j]] == 0) {
            mp[v[j]] = j;
        }
        else {
             
            ll lst = mp[v[j]];
            while(i<=lst) {
                mp[v[i]] = 0;
                i++;
            }

            mp[v[j]] = j;
        }

         ans = max(ans, j-i+1);

         j++;

       }

       cout << ans << endl;

    return 0;
}