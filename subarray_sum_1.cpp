#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    ll n, k;
    cin >> n >> k;

    vector<ll> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    map<ll, int> mp;

    ll sum = 0;
    ll ans = 0;

    for(int i=0; i<n; i++) {

        sum += nums[i];
     
        if(sum == k) ans++;
        
        if(mp.find(sum-k) != mp.end()) {
            ans += mp[sum-k];
        }

        mp[sum]++;

    }  

    cout << ans << endl;

    return 0;
}