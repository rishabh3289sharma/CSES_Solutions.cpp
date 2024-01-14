// RECURSIVE CODE

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// int mod = 1e9+7;
// int n;

// vector<vector<int>> dp;

// int solve(int curr_sum, int sum, int curr) {

//     if(curr_sum > sum || curr > n) return 0;

//     if(curr_sum == sum) return 1;

//     if(dp[curr_sum][curr] != -1) return dp[curr_sum][curr];

//     int ans = 0;

//     ans = (ans + solve(curr_sum, sum, curr+1))%mod;

//     ans = (ans + solve(curr_sum+curr, sum, curr+1))%mod;

//     return dp[curr_sum][curr] = ans;
// }

// int main() {
    
//     cin >> n;

//     if((n*(n+1))%4 != 0) {
//         cout << 0 << endl;
//     }
//     else {
    
//     int sum = (n*(n+1))/4;
//     dp.resize(sum+1, vector<int>(n+1, -1));
//     cout << solve(0, sum, 1) << endl;

//     }

//     return 0;
// }


// DP CODE

# include<iostream>
# include<bits/stdc++.h>

using namespace std;
int mod = 1e9+7;

int main() {

    int n;
    cin >> n;

    int sum = n*(n+1);

    if(sum%4 != 0) {
        cout << 0 << endl;
    }
    else {
        
        sum = (n*(n+1))/4;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        
        dp[0][0] = 1;

        for(int i=1; i<=n; i++) {
            for(int s=1; s<=sum; s++) {
                
                dp[i][s] = dp[i-1][s];

                if(s-i >= 0) {
                    dp[i][s] = dp[i][s] + dp[i-1][s-i];
                    dp[i][s] = dp[i][s] % mod;
                }

            }
        } 

    cout << dp[n][sum] << endl;

    }


    return 0;
} 

