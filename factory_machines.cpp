#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main() {

    int n, t;
    cin >> n >> t;

    vector<ll> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    ll low = 0;
    ll high = 1e18;

    ll ans = 0;

    while(low <= high) {
         
         ll mid = (low+high)/2;
       
         ll sum = 0;

         for(int i=0; i<n; i++) {

            sum += mid/v[i];
            
            if(sum >= t) break;
         
         } 

         if(sum >= t) {
            ans = mid;
            high = mid-1;
         }
         else {
            low = mid+1;
         }

    }

    cout << ans << endl;

    return 0;
}