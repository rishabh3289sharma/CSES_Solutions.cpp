//  RECURSIVE APPROACH

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// int mod = 1e9+7;

// int n;

// vector<vector<int>> memo;

// int solve(vector<string>& v, int x, int y) {
    
//     if(x >= n || y >= n || v[x][y] == '*') return 0;

//     if(x == n-1 && y == n-1) return 1;

//     if(memo[x][y] != -1) return memo[x][y];

//     int ans = 0;

//     ans = (ans + solve(v, x, y+1) + solve(v, x+1, y))%mod;

//     return memo[x][y] = ans;
// }

// int main() {

//     cin >> n;

//     vector<string> v(n);
//     memo.resize(n, vector<int>(n, -1));

//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     int res = solve(v, 0, 0);

//     cout << res << endl;

//     return 0;
// }



// DP APPROACH


#include<bits/stdc++.h>

using namespace std;
#define ll long long
int mod = 1e9+7;

int main() {

    int n;
    cin >> n;

    vector<string> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    } 

    vector<vector<int>> dp(n, vector<int>(n, 0));

    dp[n-1][n-1] = 1;

    for(int i=n-1; i>=0; i--) {

        for(int j=n-1; j>=0; j--) {
            
            if(v[i][j] != '*') {
                
                if(i < n-1) {
                    dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
                }
                if(j < n-1) {
                    dp[i][j] = (dp[i][j] + dp[i][j+1])%mod;
                }

            }
            else {
                dp[i][j] == 0;
            }

        }
    }


    if(v[n-1][n-1] == '*' || v[0][0] == '*') {
        cout << 0 << endl;
    }
    else {
        cout << dp[0][0] << endl;
    }

    return 0;
}





