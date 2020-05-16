/*
Gicen n and p, find n^p in o(logn) time
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	long long int n, p;
	cin >> n >> p;
	int ans = 1, temp = n;
	while (p) {
		if (p & 1) {
			ans *= n;
		}
		n *= n;
		p = p >> 1;
	}
	cout << ans;
	return 0;
}