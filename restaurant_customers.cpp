#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> vp;

    for(int i=0; i<n; i++) {

        int start, end;
        cin >> start >> end;

        vp.push_back({start, 1});
        vp.push_back({end, -1});

    }

    sort(vp.begin(), vp.end());

    int curr = 0;
    int mx = 0;

    for(const pair<int, int> &p : vp) {
        curr += p.second;
        mx = max(mx, curr);
    }
    
    cout << mx << endl;   
    return 0;
}