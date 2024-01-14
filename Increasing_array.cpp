#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    ll n;
    cin >> n;

    vector<ll> v(n);

    for(ll i=0; i<n; i++) {
        cin >> v[i];
    }

    ll sum = 0;

    ll curr = v[0];

    for(ll i=1; i<n; i++) {
        if(v[i] < curr) {
            sum += curr-v[i];
        }
        curr = max(curr, v[i]);
    }

    cout << sum << endl;

    return 0;
}