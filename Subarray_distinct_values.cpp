#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    int i=0, j=0;

    unordered_map<int, int> mp;
    ll ans = 0;
    int dist = 0;

    while(j < n) {

         while(i < n && (dist < k || mp[v[i]] >= 1) ) {
              
              mp[v[i]]++;
              if(mp[v[i]] == 1) dist++;
              i++; 

         }

         ans += i-j;

         mp[v[j]]--;
         if(mp[v[j]] == 0) dist--;
         j++;

    }

    cout << ans << endl;

    return 0;
}