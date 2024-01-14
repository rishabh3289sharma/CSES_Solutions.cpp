#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> v(n);

    for(int i=0; i<n; i++) { 
        
        int a, b;
        cin >> a >> b;

        v[i].first.first = a;
        v[i].first.second = b;
        v[i].second = i;

    }

    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
    // v[i].first.first      -----> arrival         
    // v[i].first.second     -----> departure
    // v[i].second           -----> index

    // pq.top().first        -----> last time occupied
    // pq.top().second       -----> room number

    int room = 0;

    vector<int> ans(n, -1);

    for(int i=0; i<n; i++) {
        
        if(pq.empty()) {
            room++;
            ans[v[i].second] = room;
            pq.push({v[i].first.second, room});
        }
        else {
      
            if(pq.top().first < v[i].first.first) {
              
               pair<int, int> tmp = pq.top();
               ans[v[i].second] = tmp.second;
               pq.pop();
               pq.push({v[i].first.second, tmp.second}); 
                
            }
            else {

               room++;
               ans[v[i].second] = room;
               pq.push({v[i].first.second, room});

            }
        }
    }        

    cout << room << endl;

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    } 


    return 0;
}
