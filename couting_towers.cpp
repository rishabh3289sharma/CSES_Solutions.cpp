// RECURSIVE CODE


// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// int mod = 1000000007;

// vector<vector<ll>> memo;

// ll solve(int num, int type) {

//     if(num == 1) return 1;
    
//     if(memo[num][type] != -1) return memo[num][type];

//     ll ans = 0;

//     if(type == 0) {
//         ans = (ans + 2*solve(num-1, type))%mod;
//         ans = (ans + solve(num-1, !type))%mod;
//     }
//     else {
//         ans = (ans + 4*solve(num-1, type))%mod;
//         ans = (ans + solve(num-1, !type))%mod;
//     }

//     return memo[num][type] = ans%mod;
// }

// int main() {
   
//     int t;
//     cin >> t;

//     memo.resize(1000002, vector<ll>(2, -1));   

//     while(t--) {
        
//         int n;
//         cin >> n;

//         // 0->a
//         // 1->b

//         cout << (solve(n, 0) + solve(n, 1))%mod << endl;

//     }


//     return 0;
// }



// DP CODE



#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int mod = 1000000007;
#define ll long long

int main() {

    int t;
    cin >> t;

    vector<vector<ll>> dp(1000002, vector<ll>(2, 0));
        dp[1][0] = 1;
        dp[1][1] = 1;
   
        for(int i=2; i<=1000000; i++) {

            dp[i][0] = (dp[i][0] + 2*dp[i-1][0])%mod;
            dp[i][0] = (dp[i][0] + dp[i-1][1])%mod;

            dp[i][1] = (dp[i][1] + 4*dp[i-1][1])%mod;
            dp[i][1] = (dp[i][1] + dp[i-1][0])%mod;

        } 

    while(t--) {
        
        int n;
        cin >> n;
        
        cout << (dp[n][0] + dp[n][1])%mod << endl;

    }

    return 0;
}