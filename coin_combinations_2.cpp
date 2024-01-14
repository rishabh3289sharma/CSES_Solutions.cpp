// RECURSIVE APPROACH

// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// const int mod = 1e9+7;
// int n;
// vector<vector<int>> dp;

// ll solve(vector<int>& v, int idx, int x) {

//    if(x == 0) return 1;
//    if(idx >= n) return 0;

//    if(dp[idx][x] != -1) return dp[idx][x];

//    ll ans = 0;
//       // taken  
//        if(v[idx] <= x) {
//          ans = (ans + solve(v, idx, x-v[idx]))%mod; 
//        }

//          ans = (ans + solve(v, idx+1, x))%mod; 

//    return dp[idx][x] = ans%mod;

// }

// int main() {

//     int x;
//     cin >> n >> x;

//     vector<int> v(n);

//     dp.resize(n+1, vector<int>(x+1, -1));

//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     cout << solve(v, 0, x) << endl;

//     return 0;
// }



// DP-APPROACH



#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int mod = 1e9+7;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    vector<ll> dp(x+1, 0);

    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int weight = 0; weight <= x; weight++) {
              
              if(v[i]<=weight) {
                  dp[weight] = (dp[weight] + dp[weight-v[i]])%mod;
              }

        }
    }

    cout << dp[x] << endl;
    
    return 0;
}











