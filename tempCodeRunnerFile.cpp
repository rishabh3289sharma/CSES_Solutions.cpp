
// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;
// int n;

// vector<vector<int>> memo;

// int solve(vector<int>& v, set<int>& s, int curr_sum, int idx) {
       
//     if(idx >= n) {
//         if(curr_sum != 0) s.insert(curr_sum);
//         return 0;
//     }

//     if(memo[idx][curr_sum] != -1) return memo[idx][curr_sum];

//     int not_taken = solve(v, s, curr_sum, idx+1);

//     int taken = solve(v, s, curr_sum + v[idx], idx+1);

//     return memo[idx][curr_sum] = not_taken + taken;

// }

// int main() {

//     cin >> n;

//     vector<int> v(n);

//     for(int i=0; i<n; i++) {
//         cin >> v[i];
//     }

//     memo.resize(n+1, vector<int>(100005, -1));

//     set<int> poss;
   
//     solve(v, poss, 0, 0);

//     cout << poss.size() << endl;

//     for(int sum : poss) {
//         cout << sum << " ";
//     }

//     cout << endl;

//     return 0;
// }
