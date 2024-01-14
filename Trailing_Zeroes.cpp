#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double valuen(double d) {

    return log(d);

}

double value5(double d) {

    return log(d);

}

// Let us consider an example, where n = 5 :
// 5! = 2 x 2 x 2 x 3 x 5

// The number of trailing zeros in the factorial of 5 will be 1 because only one pair of 2 and 5 can be made from one 5 and three 2s in the prime factors of 5!.

// In the above example, we can see that the number of 2s in prime factors is always more than or equal to the number of 5s.

// So if we count the number of 5s in the prime factors, our task is done. But how to calculate the number of 5s in prime factors of n!? An easy method of doing this would be using Legendre’s Formula, which is used to get the highest power of a prime number p in n!.

int main() {

    int n;
    cin >> n;

    int k = floor(valuen((double)n)/value5((double)5));

    int ans = 0;

    for(int i=1; i<=k; i++) {
   
         ans += floor((double)n/pow(5, i));

    }
  
    cout << ans << endl;
 
    return 0;
}