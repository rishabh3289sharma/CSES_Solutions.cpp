#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> elements(n);

    for(int i=0; i<n; i++) {
        elements[i] = i+1;
    }

    while(elements.size() > 1) {
        vector<int> supporter;
        int sz = elements.size();
        for(int i=0; i<sz; i++) {
            if(i%2 == 1) {
                cout << elements[i] << " ";
            }
            else {
                supporter.push_back(elements[i]);
            }
        }

        if(elements.size()%2 == 0) {
            elements = supporter;
        }
        else {
            int start = supporter.back();
            supporter.pop_back();
            elements = supporter;
            elements.insert(elements.begin(), start);
        }

    }

    if(elements.size() == 1) {
            cout << elements[0];
    }

    return 0;
}