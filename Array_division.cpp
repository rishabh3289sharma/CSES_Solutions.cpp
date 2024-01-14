#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define ll long long

bool is_possible(vector<int>& arr, int k, ll mid) {
       
     ll curr_sum = 0;
     int sub_cnt = 0;

    for(auto ele : arr) {
         
         if(ele > mid) return false;

         if(curr_sum + ele > mid) {
            sub_cnt++;
            curr_sum = ele;
         }
         else{
            curr_sum += ele;
         }

    } 

    sub_cnt++;

    return (sub_cnt <= k);

}

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    
    ll low = 0;
    ll high = 1e18;

    while(low <= high) {
        
        ll mid = low + (high-low)/2;
      
        if(is_possible(v, k, mid)) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }

    }
     
    cout << low << endl;

    return 0;
}