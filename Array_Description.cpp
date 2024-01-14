// RECURSIVE CODE


// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// int mod = 1000000000+7;
// int n, m;

// vector<vector<int>> dp;

// int solve(vector<int>& v, int idx, int curr) {

//     if(v[idx] != 0 && v[idx] != curr) return 0;
 
//     if(idx == n-1) return 1;

//     if(dp[idx][curr] != -1) return dp[idx][curr]; 

//     int ans = 0;

//     if(idx < n-1 && v[idx+1] == 0) {
//         for(int i = max(1, curr-1); i<=min(m, curr+1); i++) {
//             ans = (ans + solve(v, idx+1, i))%mod;
//         }
//     } 
//     else if(idx < n-1 && v[idx+1] != 0){
        
//         if(abs(v[idx+1]-curr) > 1) return 0;
        
//         ans = (ans + solve(v, idx+1, v[idx+1]))%mod;
//     }

//     return dp[idx][curr] = ans%mod;    
// }


// int main() {

//     cin >> n >> m;

//     dp.resize(n+1, vector<int>(m+2, -1));

//     vector<int> v(n);

//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     if(v[0] != 0) {
//         cout << solve(v, 0, v[0]) << endl;
//     }
//     else {
//         int ans = 0;

//         for(int i=1; i<=m; i++) {
//             ans = (ans + solve(v, 0, i))%mod;
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }



// DP APPROACH - 1



// #include<bits/stdc++.h>

// using namespace std;
// int mod = 1000000007;

// int main() {

//     int n, m;
//     cin >> n >> m;

//     vector<int> v(n);
    
//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//     if(v[0] == 0) {
//        for(int i=1; i<=m; i++) {
//          dp[1][i] = 1;
//        }
//     } 
//     else {
//         dp[1][v[0]] = 1;
//     }

//     for(int i=2; i<=n; i++) {

//         for(int k=1; k<=m; k++) {
             
//             if(v[i-1] != 0 && v[i-1] != k) {
//                 dp[i][k] = 0;
//                 continue;
//             }

//             for(int prev = max(1, k-1); prev <= min(m, k+1); prev++) {
//                 dp[i][k] = (dp[i][k] + dp[i-1][prev])%mod;
//             } 

//         }

//     }

//     int ans = 0;

//     if(v[n-1] == 0) {
//          for(int i=1; i<=m; i++) {
//             ans = (ans + dp[n][i])%mod;
//          }
//     }
//     else {
//          ans = dp[n][v[n-1]];
//     }

//     cout << ans << endl;

//     return 0;
// }



////   DP APPROACH - 2



#include<bits/stdc++.h>

using namespace std;
int mod = 1000000007;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> dp(n, vector<int>(m+1, 0));

    if(v[0] == 0) {
        for(int i=1; i<=m; i++) {
            dp[0][i] = 1;
        }
    } 
    else {
        dp[0][v[0]] = 1;
    }

    for(int i=1; i<n; i++) {
        if(v[i] == 0) {  
         
            for(int k=1; k<=m; k++) {
               
                dp[i][k] = (dp[i][k] + dp[i-1][k])%mod;

                if(k-1 >= 1) dp[i][k] = (dp[i][k] + dp[i-1][k-1])%mod;

                if(k+1 <= m) dp[i][k] = (dp[i][k] + dp[i-1][k+1])%mod;

            }
             
        }
        else {
            
            dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]])%mod;

            if(v[i]-1 >= 1) dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]-1])%mod;

            if(v[i]+1 <= m) dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][v[i]+1])%mod;

        }

    }

    int ans = 0;

    if(v[n-1] == 0) {
        
        for(int i=1; i<=m; i++) {
            ans = (ans + dp[n-1][i])%mod;
        }

    }
    else {

        ans = dp[n-1][v[n-1]];
    
    }
   
    cout << ans << endl;

    return 0;
}


