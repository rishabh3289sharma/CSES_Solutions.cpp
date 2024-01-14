#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    int ans = 0;
    vector<pair<int, int>> v(t);

        for(int i=0; i<t; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        int st = 0;
        int en = 0;

        for(int i=0; i<t; i++) {
            
            if(v[i].first < en && v[i].second > en) continue;
            else if(v[i].first >= en) {
                ans++;
                st = v[i].first;
                en = v[i].second;
            }
            else if(v[i].second <= en) {
                st = v[i].first;
                en = v[i].second;
            }

    }

    cout << ans << endl;

    return 0;
}