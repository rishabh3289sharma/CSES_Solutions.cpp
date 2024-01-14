// // 1ST APPROACH 

// // #include<iostream>
// // #include<bits/stdc++.h>
// // using namespace std;

// // int main() {

// //     int n;
// //     cin >> n;

// //     vector<int> v(n);

// //     for(int i=0; i<n; i++) {
// //         cin >> v[i];
// //     }

// //     vector<int> tmp(n, 1);

// //     int ans = 0;

// //     for(int i=0; i<n; i++) {
// //         for(int j=0; j<i; j++) {
// //             if(v[j] < v[i] && tmp[i] < tmp[j]+1) {
// //                 tmp[i] = tmp[j]+1;
// //             }
// //         }

// //         ans = max(ans, tmp[i]);
// //     }

// //     cout << ans << endl;

// //     return 0;
// // }


// // 2ND APPROACH


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

    vector<int> tmp;
    tmp.push_back(v[0]);

    for(int i=1; i<n; i++) {
        
        auto itr = lower_bound(tmp.begin(), tmp.end(), v[i]);
        
        if(itr == tmp.end()) {
            tmp.push_back(v[i]);
        }
        else {
            *itr = v[i];
        }

    }

    cout << tmp.size() << endl;

    return 0;
}
