#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

static bool comp(pair<int, int>& a, pair<int, int>& b) {

       if(a.first == b.first) return a.second > b.second;

       return a.first < b.first;

}

int main() {
    
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++) {
        
        int a, b;
        cin >> a >> b;
       
        v.push_back({a, b});        

    }  

    sort(v.begin(), v.end(), comp);

    ll curr = 0;
    ll ans = 0;

    for(int i=0; i<n; i++) {
        
       curr += v[i].first;
       
       ans += v[i].second-curr;

    }
    
    cout << ans << endl;

    return 0;
}


