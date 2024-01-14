#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;

    map<char, int> mp;

    for(auto ch : s) {

        mp[ch]++;

    }

    int one = 0;

    string single = "";

    for(auto it : mp) {
        if(it.second % 2) {
            
            if(one == 0) {
             single += it.first;
             one++;
            }
            else {
                one = 2;
            }

        }
    }

    string s1 = "";

    string s2 = "";

    if(one <= 1) {

          for(auto it:mp) {
             
              int tmp = it.second/2;

              while(tmp--) {
                  
                 s1 += it.first;
                 s2 += it.first;

              }

          }

          reverse(s2.begin(), s2.end());

          s1 = s1 + single + s2;

          cout << s1 << endl;

    }
    else {
        cout << "NO SOLUTION" << endl;
    }

    return 0;
}