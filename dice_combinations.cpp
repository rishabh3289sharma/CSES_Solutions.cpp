#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

int mod = 1e9+7;

int main() {

    int n;
    cin >> n;

    vector<ll> dp(n+1, 0);
   
    dp[0] = 1; 

    for(int i=1; i<=n; i++) {
       
        int cnt = 1;

        while(cnt <= 6 && i-cnt >= 0) { 
            dp[i] = (dp[i]%mod + dp[i-cnt]%mod)%mod;
            cnt++; 
        }

    }

    cout << dp[n] << endl;
   
    return 0;
}