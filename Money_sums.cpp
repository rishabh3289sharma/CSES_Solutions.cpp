// RECURSIVE CODE

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


// DP CODE

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) { 
        cin >> v[i];  
    }

    vector<vector<bool>> dp(n+1, vector<bool>(100005, false));

	dp[0][0] = true;

	for (int i = 1; i <= n; i++) {
		for (int sum = 0; sum <= 100000; sum++) {
			dp[i][sum] = dp[i - 1][sum];

			if (sum-v[i-1] >= 0 && dp[i-1][sum-v[i-1]]) {
				dp[i][sum] = true;
			}

		}
	}

	vector<int> possible;

	for (int sum = 1; sum <= 100000; sum++) {
		if (dp[n][sum]) { 
            possible.push_back(sum); 
        }
	}

	cout << (int)(possible.size()) << endl;

	for (int sum : possible) { 
        cout << sum << " "; 
    }

	cout << endl;

}


