#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll MOD = 1e9+7;

int main() {

    int n;
    cin >> n;

    ll ans = 1;

    for(int i=1; i<=n; i++) {
        ans = (ans*2)%MOD;
    }
    
    cout << ans << endl;

    return 0;
}




