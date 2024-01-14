
////****              RECURSIVE AND MEMO APPROACH               ****////




// #include<iostream>
// #include<bits/stdc++.h>
 
// using namespace std;
// #define ll long long
 
// int n;
// vector<int> dp;
 
// int solve(vector<int>& v, int curr_sum, int k) { 
 
//     if(curr_sum == k) return 0;
 
//     if(dp[curr_sum] != -1) return dp[curr_sum];
 
//     int ans = INT_MAX;
 
//     for(int i=0; i<n; i++) {
//         if(v[i] <= k-curr_sum) {
//             int tmp = solve(v, curr_sum+v[i], k);
//             if(tmp != INT_MAX && 1+tmp < ans) {
//                 ans = 1+tmp;
//             }
//         }
//     }
 
//     return dp[curr_sum] = ans;      
// }
 
// int main() {
   
//     int k;
//     cin >> n >> k; 
 
//     vector<int> v(n);
//     dp.resize(k+1, -1);
 
//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }
 
//     ll res = solve(v, 0, k);
 
//     if(res == INT_MAX) {
//         cout << -1 << endl;
//     }
//     else {
//         cout << res << endl;
//     }
 
//     return 0;
// }





////****              DP-APPROACH               ****////


#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x+1, INT_MAX);

    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int weight = 0; weight <= x; weight++) {
            if(weight - coins[i] >= 0) {
                dp[weight] = min(dp[weight], 1+dp[weight-coins[i]]);
            }
        }
    } 

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;

    return 0;
}