#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(ll x, ll size) {

   ll count = 0;

   for(int i=1; i<size; i++) {
     ll num = (9ll*pow(10, i-1));
     count += (num*i);
   }

   ll mi = pow(10ll, size-1);
   count += ((x-mi)*size) + 1;
   return count;

}

int main() {

    int t;
    cin >> t;

    while(t--) {
        
         ll n;
         cin >> n;

         ll sum = 0;

         ll dig = 0;

         for(int i=1; i<=18; i++) {
              
               ll num = (9ll*pow(10, i-1));

               sum += num*i;

               if(n <= sum) {
                  dig = i;
                  break;
               } 

         }

         ll lo = pow(10ll, dig-1);
         ll hi = pow(10ll, dig)-1;

         ll mid, ans = 0, index = 0;

         while(lo <= hi) {
          
          mid = (lo+hi)/2;

          ll value = solve(mid, dig);

          if(value <= n) {
             
             index = max(index, value);
             ans = max(ans, mid);
             lo = mid+1; 
          }
          else{
            hi = mid-1;
          }

      }

      string str = to_string(ans);
    
      for(auto ch : str) {
         if(n == index) {
           cout << (ch-'0') << endl;
           break;
         }
         index++;
      }

    }
    return 0;
}