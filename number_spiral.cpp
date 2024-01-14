#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    ll t;
    cin >> t;

    while(t--) {
        
        ll x, y;

        cin >> x >> y;

        ll mx = max(x, y);

        ll ans = -1;

        if(mx%2) {
            
            ll mxa = mx;
            ll mya = 1;

            ans = (mx-1)*(mx-1) + (ll)1 + abs(mxa-x) + abs(mya-y);

        }
        else {

            ll mxa = 1;
            ll mya = mx;

            ans = (mx-1)*(mx-1) + (ll)1 + abs(mxa-x) + abs(mya-y);

        }

        cout << ans << endl;

    }

    return 0;
}