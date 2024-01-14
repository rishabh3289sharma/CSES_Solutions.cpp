#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int mod = 1e9+7;

vector<bool> visited;
vector<vector<int>> adj;

void dfs(int curr, vector<vector<int>>& adj) {
     
     visited[curr] = true;

     for(auto next : adj[curr]) {
        if(!visited[next]) {
            dfs(next, adj);
        }
     }

}

int main() {

    int n, m;
    cin >> n >> m;

    visited.resize(n, false);

    adj.resize(n);

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int ans = 0;
    int lst = -1;

    vector<vector<int>> res;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans++;
            dfs(i, adj);
            if(lst != -1) res.push_back({lst, i});
            lst = i;
        }
    }


    cout << ans-1 << endl;

    for(int i=1; i<ans; i++) {
        cout << res[i-1][0]+1 << " " << res[i-1][1]+1 << endl;
    }


    return 0;
}