#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    map<int, pair<int, int>> mp;

    bool ans = false;
 
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            
            int req = x-v[i]-v[j];

            if(mp.find(req) != mp.end()) {
                cout << mp[req].first+1 << " " << mp[req].second+1 << " " << i+1 << " " << j+1;
                ans = true;
                break;
            }

        }

        if(ans) break;

        for(int j=0; j<i; j++) {
            mp[v[i]+v[j]] = {i, j};
        }  

    }
    

    if(!ans) {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}