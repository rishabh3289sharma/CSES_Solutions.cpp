#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
 
    int x, n;
    cin >> x >> n;
 
    vector<int> v(n);
 
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
 
    set<int> s;
    multiset<int> mst;
 
    s.insert(0);
    s.insert(x);
    mst.insert(x);
 
    for(int i=0; i<n; i++) {
 
        int curr = v[i];
 
        auto it2 = s.upper_bound(curr);
        auto it1 = it2;
        it1--;   
 
        mst.erase(mst.find(*it2-*it1));
        mst.insert(*it2-curr);
        mst.insert(curr-*it1);
        s.insert(curr);
 
        auto ans = mst.end();
        ans--;
 
        cout << *ans << " ";
    }
 
    return 0;
}















