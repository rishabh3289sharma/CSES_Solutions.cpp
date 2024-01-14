#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    stack<pair<int, int>> st;
  
    for(int i=0; i<n; i++) {

        if(st.empty()) {
            
            cout << 0 << " ";
            st.push({v[i], i+1});

        }
        else if(!st.empty() && st.top().first < v[i]) {

            cout << st.top().second << " ";  

            st.push({v[i], i+1});

        }
        else {
            
            while(!st.empty() && st.top().first >= v[i]) { 
                st.pop();
            }

            if(st.empty()) {
                cout << 0 << " ";
            }         
            else {
                cout << st.top().second << " ";
            }

            st.push({v[i], i+1});

        } 

    }

    return 0;
}