#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {

    string s;
    cin >> s;

    int j=0;

    int n = s.length();

    int ans = 1;

    for(int i=0; i<n; i++) {
     
        while(j < n && s[j] == s[i]) {
              ans = max(ans, j-i+1);
              j++;
        }

    }

    cout << ans;

    return 0;
}