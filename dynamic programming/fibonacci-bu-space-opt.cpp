#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    if (n == 0 || n == 1) {
        cout << n;
    }
    else{
        ll a = 0, b = 1, c;
        n -= 2;
        while (n--) {
            c = a+b;
            a = b;
            b = c;
        }
        cout << c;
    }
    return 0;
}