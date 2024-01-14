// RECURSIVE CODE

// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// #define ll long long
// vector<vector<ll>> memo;

// ll solve(vector<ll>& v, int i, int j, int turn) {
    
//     if(i > j) return 0;
    
//     if(memo[i][j] != -1) return memo[i][j];

//     if(turn == 0) {
//         ll a = v[i] + solve(v, i+1, j, 1);
//         ll b = v[j] + solve(v, i, j-1, 1);
//         return memo[i][j] = max(a, b);
//     }
//     else {
//         ll a = solve(v, i+1, j, 0);
//         ll b = solve(v, i, j-1, 0);
//         return memo[i][j] = min(a, b);
//     }

// }

// int main() {

//     int n;
//     cin >> n;

//     vector<ll> v(n);

//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     memo.resize(n+1, vector<ll>(n+1, -1));

//     ll res = solve(v, 0, n-1, 0);

//     cout << res << endl;

//     return 0;
// }


// DP CODE

