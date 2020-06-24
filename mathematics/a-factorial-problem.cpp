/*
Mike found an interesting problem. In this problem you are given two integers, n and k. You need to find the the maximum value of x, such that, n! % kx = 0.

Input Format
First line contains number of test cases, T. Each test case contains two integers each, n and k.

Constraints
1<=T<=20 1<=n<=10^8 2<=k<=10^8

Output Format
Print the value of x for each test case.

Sample Input
2
5 2
1000 2
Sample Output
3
994
Explanation
In the first test case, n = 5 and k = 2. So, n! = 120. n! % 2^0 = 0, n! % 2^1 = 0, n! % 2^2 = 0, n! % 2^3 = 0, n! % 2^4 = 8, n! % 2^5 = 24, n! % 2^6 = 56, n! % 2^7 = 120. So, the answer should be 3.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, x = LLONG_MAX;
        cin >> n >> k;
        for (ll prime = 2; (prime*prime <= k) && (k > 1); prime++) {
            ll kcount = 0;
            if (k % prime == 0) {
                while (k % prime == 0) {
                    k = k/prime;
                    kcount++;
                }
            }
            ll p = prime, ncount = 0;
            while (p <= n) {
                ncount += (n/p);
                p *= prime;
            }
            if (kcount != 0)
                x = min(x, ncount/kcount);
        }
        if (k > 1) {
            ll kcount = 0, ncount = 0, prime = k, p = k;
            while (k > 1) {
                k = k/k;
                kcount++;
            }
            while (p <= n) {
                ncount += (n/p);
                p *= prime;
            }
            if (kcount != 0)
                x = min(x, ncount/kcount);
        }
        if (x == LLONG_MAX) {
            x = 0;
        }
        cout << x << endl;
    }
    return 0;
}
