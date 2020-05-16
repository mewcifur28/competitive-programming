#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int ans = 0, temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ans = ans ^ temp;
	}
	cout << ans;
	return 0;
}