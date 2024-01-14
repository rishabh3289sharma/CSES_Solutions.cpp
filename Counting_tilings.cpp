#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int mod = 1e9+7;

vector<vector<int>> dp;

void generate(int curr_mask, int nxt_mask, int row, int n, vector<int>& nxt_masks) {

    if(row == n+1) {
        nxt_masks.push_back(nxt_mask);
        return;
    }

    if( (curr_mask & (1<<row)) != 0) {
        generate(curr_mask, nxt_mask, row+1, n, nxt_masks);
    }

    if( (curr_mask & (1<<row)) == 0) {
        if(row != n && (curr_mask & (1<<(row+1))) == 0) {
            generate(curr_mask, nxt_mask, row+2, n, nxt_masks);
        }

        generate(curr_mask, nxt_mask+(1<<row), row+1, n, nxt_masks);
    }

}

int solve(int col, int mask, int n, int m) {
   
    if(col == m+1) {
        return mask == 0 ? 1 : 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];

    int ans = 0;
    vector<int> nxt_masks;
    generate(mask, 0, 1, n, nxt_masks);
    
    for(int nxt_mask : nxt_masks) {
        ans = (ans + solve(col+1, nxt_mask, n, m))%mod;
    }
   
    return dp[col][mask] = ans;
}

int main() {

    int n, m;
    cin >> n >> m;

    dp.resize(1001, vector<int>(1<<11, -1));

    cout << solve(1, 0, n, m) << endl;

    return 0;
}