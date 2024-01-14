// RECURSIVE APPROACH

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// int mod = 1e9+7;

// vector<vector<int>> dp;

// int n;

// int solve(vector<pair<int, int>>& v, int idx, int x) {

//     if(idx >= n) return 0;

//     if(x <= 0) return 0;

//     if(dp[idx][x] != -1) return dp[idx][x];

//     int ans = 0;
    
    
//     if(v[idx].first <= x) {
//         ans = max(ans, v[idx].second + solve(v, idx+1, x-v[idx].first));
//     }   

//     ans = max(ans, solve(v, idx+1, x)); 
        
//     return dp[idx][x] = ans;
// }

// int main() {

//     int x;
//     cin >> n >> x;

//     vector<pair<int, int>> v(n);

//     for(int i=0; i<n; i++) {
//         cin >> v[i].first; 
//     } 

//     for(int i=0; i<n; i++) {
//         cin >> v[i].second;
//     }

//     dp.resize(1005, vector<int>(100005, -1));

//     // v[i].first      ----->  price
//     // v[i].second     ----->  pages
    
//     int res = solve(v, 0, x);

//     cout << res << endl;

//     return 0;
// }


///   DP-APPROACH    ///


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].first;
    }

    for(int i=0; i<n; i++) {
        cin >> v[i].second;
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
     
    // v[i].first  = price;
    // v[i].second = pages;

    dp[0][0] = 0;
  
    for(int i=1; i<=n; i++) {
       
        for(int price = 0; price<=x; price++) {
                 
                 dp[i][price] = dp[i-1][price];

                 if(v[i-1].first <= price) {
                      dp[i][price] = max(dp[i][price], v[i-1].second + dp[i-1][price-v[i-1].first]);
                 }

        }

    }
   
    cout << dp[n][x] << endl;

    return 0;
}
