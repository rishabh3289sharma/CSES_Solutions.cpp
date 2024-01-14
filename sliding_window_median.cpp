#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

multiset<ll> low;
multiset<ll> up;
int n, k;

void ins(ll val) {

     int a = *low.rbegin();

     if(val > a) {
        up.insert(val);
        if(up.size() > k/2) {
            low.insert(*up.begin());
            up.erase(up.find(*up.begin()));
        }  
     }
     else{
        low.insert(val);
        if(low.size() > (k+1)/2) {
            up.insert(*low.rbegin());
            low.erase(low.find(*low.rbegin()));
        } 
     }
}

void er(ll val) {
    
    if(up.find(val) != up.end()) up.erase(up.find(val));
    else low.erase(low.find(val));

    if(low.empty()) {
        low.insert(*up.begin());
        up.erase(up.find(*up.begin()));
    } 

}

int main() {

    cin >> n >> k;

    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    low.insert(arr[0]);

    for(int i=1; i<k; i++) {
        ins(arr[i]);
    }

    cout << *low.rbegin() << " ";

    for(int i=k; i<n; i++) {
        if(k == 1) {
            ins(arr[i]);
            er(arr[i-k]);
        }
        else {
            er(arr[i-k]);
            ins(arr[i]);
        }

        cout << *low.rbegin() << " ";
    }

    cout << endl;

    return 0;
}