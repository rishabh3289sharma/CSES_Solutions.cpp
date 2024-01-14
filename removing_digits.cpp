// RECURSIVE APPROACH

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// #define ll long long

// int mod = 1e9+7;

// vector<int> dp;

// int solve(int num) {

//     if(num == 0) return 0;

//     if(dp[num] != 0) return dp[num];
    
//     int ans = INT_MAX;

//     vector<int> dig;

//     int tmp = num;

//     while(tmp) {

//        dig.push_back(tmp%10);

//        tmp = tmp/10; 

//     }

//     for(int i=0; i<(int)dig.size(); i++) {

//        if(dig[i] == 0) continue; 

//        ans = min(ans, 1 + solve(num-dig[i]) ); 

//     }

//     return dp[num] = ans;
// }


// int main() {

//     int n;
//     cin >> n;

//     dp.resize(n+1, 0);

//     int res = solve(n);
    
//     cout << res << endl;

//     return 0;
// }


// DP APPROACH


#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i=1; i<=n; i++) {

        int tmp = i;

        while(tmp > 0) {
            if(tmp%10 != 0) {
                dp[i] = min(dp[i], 1+dp[i-(tmp%10)]);
            }
                tmp /= 10;
        }

    }

    cout << dp[n] << endl;

    return 0;
}
