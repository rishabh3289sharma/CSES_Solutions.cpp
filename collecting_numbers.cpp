#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
  
    int n;
    cin >> n;

    vector<int> idx(n+1, 0);

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x; 
        idx[x] = i;
    }

    int ans = 1;
    int curr = 1;

    for(int i=1; i<=n; i++) {
        if(curr > idx[i]) {
            ans++;
        }
        curr = idx[i];
    }
    
    cout << ans << endl;

    return 0;
}