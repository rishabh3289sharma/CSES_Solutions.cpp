#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void tower_of_hanoi(int n, int st, int mid, int end) {
    if(n == 0) {
        return;
    }
    
    tower_of_hanoi(n-1, st, end, mid);

    cout << st << ' ' << end << endl;

    tower_of_hanoi(n-1, mid, st, end);

}

int main() {

    int n;
    cin >> n;

    cout << (1<<n)-1 << endl;

    tower_of_hanoi(n, 1, 2, 3);

    return 0;
}