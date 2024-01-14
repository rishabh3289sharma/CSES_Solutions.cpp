#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

set<string> ans;

void solve(string prefix, string suffix) {
   
     if(suffix.length() == 0) {
        ans.insert(prefix);
        return;
     }

     for(int i=0; i<suffix.length(); i++) {
        solve(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i+1));
     }

}

int main() {

    string s;
    cin >> s;

    solve("", s);
    cout << ans.size() << endl;

    for(auto st : ans) {
        cout << st << endl;
    }

    return 0;
}
