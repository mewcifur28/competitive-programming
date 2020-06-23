#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll fastPow(ll n, ll p) {
	if (p == 0) {
		return 1;
	}
	ll smallAns = fastPow(n, p/2);
	smallAns *= smallAns;
	if (p&1) {
		smallAns *= n;
	}
	return smallAns;
}
int main() {
	ll n, p;
	cin >> n >> p;
	cout << fastPow(n, p);
	return 0;
}