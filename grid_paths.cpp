#include<iostream>
#include<bits/stdc++.h>

using namepsace std;

bool visited[n][n];
int reserved[49];

// U = 0;
// R = 1;
// D = 2;
// L = 3;

int n = 7;

void solve(int r, int c, int &ans, int& idx) {

     if(r == n-1 && c == 0, idx == 48) {
        ans += (idx == n*n-1);
        return;
     } 

     if((r+1 == 7) || )



}

int main(){
   
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '?') {
            reserved[i] = -1;
        }
        else if(s[i] == 'U') {
            reserved[i] = 0;
        }
        else if(s[i] == 'R') {
            reserved[i] = 1;
        }
        else if(s[i] == 'D') {
            reserved[i] = 2;
        }
        else if(s[i] == 'L') {
            reserved[i] = 3;
        }
    }

    int ans = 0;
    int idx = 0;

    solve(0, 0, ans, idx);

    cout << ans << endl;

    return 0; 
}














































// #include<iostream>
// #include<bits/stdc++.h>

// using namespace std;

// int solve(vector<vector<int>>& grid, int x, int y, string s, int idx) {

//     if(x == 6 && y == 0) {
        //    if(idx == 48) return 1;
        //    return 0;
//     }

//     if(idx >= s.size() || x>=7 || x<0 || y>=7 || y<0) {
//         return 0;
//     }

//     int ans = 0;

//     if(s[idx] == 'R' && y+1 < 7&& grid[x][y+1] != 1) {
        
//         grid[x][y+1] = 1;
//         ans += solve(grid, x, y+1, s, idx+1);
//         grid[x][y+1] = 0;

//     }
//     else if(s[idx] == 'L' && y-1 >= 0 && grid[x][y-1] != 1) {
//         grid[x][y-1] = 1;
//         ans += solve(grid, x, y-1, s, idx+1);
//         grid[x][y-1] = 0;
//     }
//     else if(s[idx] == 'U' && x-1 >=0 && grid[x-1][y] != 1) {
//         grid[x-1][y] = 1;
//         ans += solve(grid, x-1, y, s, idx+1); 
//         grid[x-1][y] = 0;
//     }
//     else if(s[idx] == 'D' && x+1<7 && grid[x+1][y] != 1) {
//         grid[x+1][y] = 1;
//         ans += solve(grid, x+1, y, s, idx+1);
//         grid[x+1][y] = 0;
//     }
//     else {
      
//         if(y+1 < 7 && grid[x][y+1] != 1) {
//             grid[x][y+1] = 1;
//         ans += solve(grid, x, y+1, s, idx+1);
//             grid[x][y+1] = 0;
//         } 

//         if(y-1 >= 0 && grid[x][y-1] != 1) {
//             grid[x][y-1] = 1;
//             ans += solve(grid, x, y-1, s, idx+1);
//             grid[x][y-1] = 0;
//         }

//         if(x-1 >= 0 && grid[x-1][y] != 1) {
//             grid[x-1][y] = 1;
//         ans += solve(grid, x-1, y, s, idx+1);
//             grid[x-1][y] = 0;
//         }

//         if(x+1 < 7 && grid[x+1][y] != 1) {
//             grid[x+1][y] = 1;
//         ans += solve(grid, x+1, y, s, idx+1);
//             grid[x+1][y] = 0;
//         }

//     }

//     return ans; 
// }


// int main() {

//     string s;
//     cin >> s;

//     vector<vector<int>> grid(7, vector<int>(7, 0));
    
//     grid[0][0] = 1;

//     cout << solve(grid, 0, 0, s, 0) << endl;

//     return 0;
// }