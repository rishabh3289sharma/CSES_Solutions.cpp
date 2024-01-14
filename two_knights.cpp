#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

// Note that when we have two knights threatening each other, it actually forms either a 2×3
//  or 3×2
//  board. And for each of 2×3
//  and 3×2
//  boards, there are 2
//  ways of placing two knights so that they threaten each other. So, what we should do is to count how many 2×3
//  and 3×2
//  squares on n×n
//  board. For general n
// , the answer is
// (n−1)(n−2)+(n−2)(n−1)=2(n−1)(n−2)
// And for each 2×3
//  and 3×2
//  board, there are 2
//  ways of placing the knights so that they threaten each other. Therefore, in total there are
// 2⋅2(n−1)(n−2)=4(n−1)(n−2)
// ways of placing two knights so that they threaten each other. So what you are looking for is
// n2(n2−1)2−4(n−1)(n−2)

int main() {
    
    ll n;
    cin >> n;
    
    ll ans = 0;

    for(ll i=1; i<=n; i++) {

        if(i == 1) {
            cout << 0 << endl;
        }
        else if(i == 2) {
            cout << 6 << endl;
        }
        else {
            ll sz = i*i; 
            ans = (sz*(sz-1))/2 - 4*(i-1)*(i-2);
            cout << ans << endl;
        }
    
    }

    return 0;
}