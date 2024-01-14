#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll ans = 1e18;
ll sum = 0;

void solve(vector<ll> v, ll currsum, ll total, int i) {

     ll sum2 = total - currsum;

     if(i == (int)v.size()-1) {
         ans = min(ans, abs(sum2-currsum));
         return;
     }

     solve(v, currsum+v[i], total, i+1);
     solve(v, currsum, total, i+1);

}


int main() {

    int n;
    cin >> n;

    vector<ll> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    sum = 0;

    for(int i=0; i<n; i++) {
        sum += v[i];
    }

    vector<ll> tmp;

    solve(v, 0, sum, 0);
    
    cout << ans << endl;
    
    return 0;
}


// Apple division problem can be solved using recursion because contrain is  too small so in can be done by recursion.
// First we generate all subsequence of weight and which subset-sum difference is minimum we will print that ans.
// For generating one subset we will use recursion for every element of array we have two choices either take it or not to take it. 
// let say the entire array sum is  S.
// and one of Subsequence sum is x so the sum of another segment of the array will be S-x . so the difference of two subsets of array is 
//  abs((totalsum-currsum) - currsum);

// currsum denote the sum of one subsequence.

// so we will make recursive call now and return minimum ans 