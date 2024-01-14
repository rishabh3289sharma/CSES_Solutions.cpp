// RECURSIVE CODE

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> memo;

// int solve(int a, int b) {

//     if(a == b) return 0;
   
//     if(a == 1) return b-1;
//     if(b == 1) return a-1;

//     if(memo[a][b] != -1) return memo[a][b];
    
//     int ans = INT_MAX;

//     for(int i=1; i<b; i++) {
//         ans = min(ans, 1+solve(a, i)+solve(a, b-i));
//     }

//     for(int i=1; i<a; i++) {
//         ans = min(ans, 1+solve(i, b)+solve(a-i, b));
//     }

//     return memo[a][b] = ans;
// }

// int main() {

//     int a, b;
//     cin >> a >> b;

//     memo.resize(501, vector<int>(501, -1));

//     cout << solve(a, b) << endl;

//     return 0;
// }



// DP CODE


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
     
    dp[0][0] = 0; 

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            
            if(i==j) {
                dp[i][j] = 0 ;
                continue;
            }

            for(int v=1; v<j; v++) {
                dp[i][j] = min(dp[i][j], 1+dp[i][v] + dp[i][j-v]);
            }

            for(int h=1; h<i; h++) {
                dp[i][j] = min(dp[i][j], 1+dp[h][j]+dp[i-h][j]);
            }

        }
    }

    cout << dp[a][b] << endl;

    return 0;
}