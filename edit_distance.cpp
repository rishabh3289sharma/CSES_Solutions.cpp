// RECURSIVE CODE

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> dp;

// int solve(string s1, string s2) {

//     int n = s1.size();
//     int m = s2.size();
    
//     if(s1.size()==0 || s2.size() == 0) {
//         return max(s1.size(), s2.size());
//     }
   
//     if(dp[n][m] != -1) return dp[n][m];    

//     int ans = INT_MAX;

//     if(s1[0] == s2[0]) {
//         ans = min(ans, solve(s1.substr(1), s2.substr(1)));
//     }
//     else {
//         int a = 1 + solve(s1, s2.substr(1));
//         int b = 1 + solve(s1.substr(1), s2);
//         int c = 1 + solve(s1.substr(1), s2.substr(1));
//         ans = min(ans, min(a, min(b, c)));
//     }

//     return dp[n][m] = ans;
// }

// int main() {
   
//     string s1, s2;

//     cin >> s1 >> s2;

//     dp.resize(s1.size()+1, vector<int>(s2.size()+1, -1));

//     cout << solve(s1, s2) << endl;

//     return 0;
// }



// DP CODE



#include<bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++) {
        dp[i][0] = i;
    }

    for(int j=0; j<=m; j++) {
        dp[0][j] = j;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else { 
                int a = 1 + dp[i-1][j];
                int b = 1 + dp[i][j-1];
                int c = 1 + dp[i-1][j-1];
                dp[i][j] = min(a, min(b, c));
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}


