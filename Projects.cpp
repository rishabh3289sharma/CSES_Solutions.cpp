// RECURSIVE CODE

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll n;
vector<ll> dp;
vector<ll> first;

ll solve(vector<vector<ll>>& v, ll idx) {
   
    if(idx == n) return 0;

    if(dp[idx] != -1) return dp[idx];
     
    auto itr = upper_bound(first.begin(), first.end(), v[idx][1]);
     
    ll j = itr-first.begin(); 

    ll ans = max(v[idx][2] + solve(v, j), solve(v, idx+1));

     return dp[idx] = ans;
}


int main() {

    cin >> n;

    vector<vector<ll>> v(n);

    for(int i=0; i<n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;

        v[i].push_back(x);
        v[i].push_back(y);
        v[i].push_back(z);
    }

    for(int i=0; i<n; i++) {
        first.push_back(v[i][0]);
    }

    sort(first.begin(), first.end());

    dp.resize(n+1, -1);

    sort(v.begin(), v.end());

    cout << solve(v, 0) << endl;

    return 0;
}










