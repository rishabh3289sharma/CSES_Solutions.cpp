#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    ll n;
    cin >> n;


    ll tmp = (n*(n+1))/2;

    vector<ll> v(n+1, 1);

    ll cnt = 0;

    if(tmp%2) {
        cout << "NO" << endl;
    }
    else {
          
        cout << "YES" << endl;
        tmp = tmp/2;
        for(ll i=n; i>=0 && tmp > 0; i--) {
             
             if(i <= tmp) {
                tmp -= i;
                v[i] = -1;
                cnt++;
             }
             else if(i > tmp) {
                v[tmp] = -1;
                tmp = 0;
                cnt++;
             }

        }

        cout << n-cnt << endl;

        for(int i=1; i<=n; i++) {
            if(v[i] == 1) {
            cout << i << " ";
            }
        }

        cout << endl;

        cout << cnt << endl;

        for(int i=1; i<=n; i++) {
            if(v[i] == -1) {
                cout << i << " ";
            }
        }
        
        cout << endl;

    }

    return 0;
}