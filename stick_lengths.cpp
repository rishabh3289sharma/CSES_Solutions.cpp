#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    int n;
    cin >> n;

    vector<ll> l(n);

    for(int i=0; i<n; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());

    ll median = l[n/2];

    ll ans1 = 0;

    for(int i=0; i<n; i++) {
        ans1 += abs(l[i]-median);
    }

    cout << ans1 << endl; 

    return 0;
}