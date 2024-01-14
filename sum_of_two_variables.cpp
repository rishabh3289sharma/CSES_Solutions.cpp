#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    int i=0; 

    int j = n-1;

    bool ans = false;

    while(i<j) {
        if(v[i].first + v[j].first > x) j--;
        else if(v[i].first + v[j].first < x) i++;
        else {
            cout << v[i].second+1 << " " << v[j].second+1 << endl;
            ans = true;
            break;
        }
    }

    if(!ans) cout << "IMPOSSIBLE" << endl;

    return 0;
}