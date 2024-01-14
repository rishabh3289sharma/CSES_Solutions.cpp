#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int n, m;

void dfs(vector<vector<char>>& v, int i, int j) {

     v[i][j] = '#';

     if(i+1 < n && v[i+1][j] == '.') {
        dfs(v, i+1, j);
     } 

     if(i-1 >= 0 && v[i-1][j] == '.') {
        dfs(v, i-1, j);
     }

     if(j+1 < m && v[i][j+1] == '.') {
        dfs(v, i, j+1);
     }

     if(j-1 >= 0 && v[i][j-1] == '.') {
        dfs(v, i, j-1);
     }

}

int main() {

    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j] == '.') {
                ans++;
                dfs(v, i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}