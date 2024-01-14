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

    bool ans = false;
    
    map<int, int> mp;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {

        if(mp.find(x-v[i]-v[j]) != mp.end()) {
            cout << mp[x-v[i]-v[j]]+1 << " " << i+1 << " " << j+1 << endl; 
            ans = true;
            break;
          }
          
        }

        mp[v[i]] = i;
    }

    if(!ans) {
        cout << "IMPOSSIBLE" << endl;
    }   

    return 0;
}