#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    
    int n;
    cin >> n;

    vector<ll> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    ll ans = 0;
    ll sum = 0;

    map<ll, int> mp;
   
    for(int i=0; i<n; i++) {
        
        sum += v[i];

        if(sum%n == 0) ans++;

        if(mp.find((sum%n+n)%n) != mp.end()) {
            ans += mp[(sum%n+n)%n];
        }

        mp[(sum%n+n)%n]++;

    }        

    cout << ans << endl;

    return 0;
}