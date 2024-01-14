#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
   
    int n;
    cin >> n;

    vector<string> gray_code;

    gray_code.push_back("");

    for(int i=0; i<n; i++) {
        int size = gray_code.size();
        for(int j=size-1; j>=0; j--) {
            gray_code.push_back(gray_code[j]);
        }
        size *= 2;
        for(int j=0; j<size; j++) {
            if(j < gray_code.size()/2){
                gray_code[j] += "0";
            }
            else {
                gray_code[j] += "1";
            }
        }
    }

    for(int i=0; i<gray_code.size(); i++) {
        cout << gray_code[i] << endl;
    }
    
    return 0;
}

// If you read the statement carefully, you will notice a little hint. We are asked to "list all 
// 2
// n
//  bit strings", which means that there is a way of reordering all the possible bit strings that satisfies our original requirements. It also indicates that generating this list might require doubling its size 
// N
//  times (and that is indeed part of the solution).

// One possible solution to this problem is to start with a list of two elements {"0", "1"} . The idea is to duplicate this list and append it to the original list in reverse order, so that we get {"0", "1", "1", "0"} . The final step is to append a "0" to the first half and a "1" to the second half of the resulting list. We only need to repeat this process 
// N
//  times.


// The trick is to understand that by reversing and appending a copy of the list to the original, the middle elements are the same, differing only by the newly added bit.

// Since we have to generate every possible string and store it in a list, the time and space complexities are 
// O(2^n).