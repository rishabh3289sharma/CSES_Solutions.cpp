#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    queue<int> q;
    
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);

    q.push(0);
    visited[0] = true;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> path(n);
    vector<int> dist(n, 0);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int next : adj[curr]) {
            if(!visited[next]) {
                dist[next] = dist[curr]+1;
                visited[next] = true;
                path[next] = curr;
                q.push(next);
            }
        }
    }


    if(!visited[n-1]) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        int dis = dist[n-1]+1;
        cout << dis << endl;
        vector<int> ans(dis);
        int lst = n-1; 
        for(int i=dis-1; i>=0; i--) {
            ans[i] = lst;
            lst = path[lst];
        }

        for(int i=0; i<dis; i++) {
            cout << ans[i]+1 << " ";
        }

        cout << endl;
    }

    return 0;
}