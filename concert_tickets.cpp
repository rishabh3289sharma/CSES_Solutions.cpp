#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    multiset<int> price;
    vector<int> mxprice(m);

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        price.insert(x);
    }

    for(int i=0; i<m; i++) {
        cin >> mxprice[i];
    }


    for(int i=0; i<m; i++) {

        auto tmp = price.upper_bound(mxprice[i]);

        if(tmp != price.begin()) {
            cout << *(--tmp) << endl;
            price.erase(tmp);  
        }
        else {
            cout << -1 << endl;
        }

    }
   
    return 0;
}