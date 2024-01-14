#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
   
    int n;
    cin >> n;

    vector<int> v(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    vector<ll> dp(n+1, 0);

    dp[0] = 0;
     
    ll ans = 0; 

    for(int i=1; i<=n; i++) {
        if(v[i] > dp[i-1]+1) {
            ans = dp[i-1]+1;
            break;
        } 

        dp[i] = dp[i-1]+v[i];        
    }     

    if(ans == 0) {
        cout << dp[n]+1 << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}