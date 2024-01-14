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

    vector<int> ans;
    ans.push_back(v[0]);

    for(int i=1; i<n; i++) {
       
       auto tmp = upper_bound(ans.begin(), ans.end(), v[i]);

       if(tmp == ans.end()) {
          ans.push_back(v[i]);
       }
       else{ 
          int idx = tmp-ans.begin();
          ans[idx] = v[i]; 
       }

    }

    cout << ans.size() << endl;

    return 0;
}