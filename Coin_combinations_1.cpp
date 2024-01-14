
// // RECURSIVE APPROACH

// // #include<iostream>
// // #include<bits/stdc++.h>

// // using namespace std;
// // #define ll long long
// // int mod = 1e9+7;

// // vector<ll> dp;

// // ll solve(vector<int>& v, int n, int x) {
   
// //    if(x == 0) return 1;

// //    if(dp[x] != -1) return dp[x];
   
// //    ll ans = 0;
 
// //    for(int i=0; i<n; i++) {

// //        if(v[i] <= x) {
// //         ans = (ans%mod + solve(v, n, x-v[i])%mod)%mod;
// //        } 

// //    }

// //    return dp[x] = ans%mod;
// // }

// // int main() {

// //     int n, x;
// //     cin >> n >> x;

// //     vector<int> v(n);

// //     for(int i=0; i<n; i++) {
// //         cin >> v[i];
// //     }

// //     dp.resize(x+1, -1);

// //     ll res = solve(v, n, x);

// //     cout << res%mod << endl;

// //     return 0;
// // }


// // DP-APPROACH


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> coins(n);

	for (int i = 0; i < n; i++) { 
        cin >> coins[i]; 
    }

    vector<ll> dp(x+1, 0);

	dp[0] = 1;

	for (int weight = 0; weight <= x; weight++) {
		for (int i = 0; i < n; i++) {
			if (weight - coins[i] >= 0) {
				dp[weight] = (dp[weight] + dp[weight - coins[i]])%MOD;
			}
		}
	}

	cout << dp[x] << endl;

    return 0;
}
