#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool issolverow(vector<string>& vs, int x, int y) {

     for(int j=0; j<8; j++) {
        if(vs[x][j] == 'q' && j != y) return false;
     } 

     return true;
}

bool issolvecol(vector<string>& vs, int x, int y) {

     for(int i=0; i<8; i++) {
        if(vs[i][y] == 'q' && i != x) return false;
     }

     return true;
}

bool isdiagonal(vector<string>& vs, int x, int y) {
     
     int i = x-1;
     int j = y-1;

     while(i>=0 && j >=0) {
        if(vs[i][j] == 'q') return false;
        j--;
        i--;
     }

     i = x+1;
     j = y+1;

     while(i<8 && j<8) {
        if(vs[i][j] == 'q') return false; 
        j++;
        i++;
     }

     i = x+1;
     j = y-1;

     while(i<8 && j>=0) {
        if(vs[i][j] == 'q') return false;
        i++;
        j--;
     }

     i = x-1;
     j = y+1;

     while(i>=0 && j<8) {
         if(vs[i][j] == 'q') return false;
         i--;
         j++;  
     }

     return true;
}

bool issafe(vector<string>& vs, int x, int y) {

     if(issolverow(vs, x, y) && issolvecol(vs, x, y) && isdiagonal(vs, x, y)) return true;

     return false;
}

int solve(vector<string>& vs, int r, int &ans) {

     if(r == 8) {
        return 1;
     }
     else {

     int ans = 0;

     for(int col = 0; col<8; col++) {

          if(vs[r][col] == '.' && issafe(vs, r, col) ) {
             
              vs[r][col] = 'q';

              ans += solve(vs, r+1, ans);

              vs[r][col] = '.'; 

          }

       }
       
       return ans;
     }

}

int main() {

    vector<string> vs(8);
    
    for(int i=0; i<8; i++) {

        cin >> vs[i];

    }

    int ans = 0;

    cout << solve(vs, 0, ans) << endl;

    return 0;
}