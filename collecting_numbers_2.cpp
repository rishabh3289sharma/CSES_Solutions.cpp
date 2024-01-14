#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> idx(n+1, 0);
    vector<int> v(n+1);

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        idx[x] = i;
        v[i] = x;
    }

    int curr = 1;
    int ans = 1;

    for(int i=1; i<=n; i++) {
         
        if(curr > idx[i]) ans++;

        curr = idx[i]; 

    }

    while(m--) {

        int x, y;
        cin >> x >> y;
   
        int r = v[x];
        int s = v[y];

        swap(v[x], v[y]);

        if(idx[r] <= )
        
    }

    return 0;
}