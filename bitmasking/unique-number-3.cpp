#include<bits/stdc++.h>
using namespace std;
void dec2bin(int n, vector<int> &uniqueNum, int Size) {
	for (int i = Size - 1; (i >= 0) || n; i--) {
		uniqueNum[i] += n & 1;
		uniqueNum[i] = uniqueNum[i] % 3;
		n = n >> 1;
	}
}
int main() {
	int Size = sizeof(int) * 4;
	int n;
	cin >> n;
	vector<int> v(n), uniqueNum(Size);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dec2bin(v[i], uniqueNum, Size);
	}
	int ans = 0;
	for (int i = Size - 1; i >= 0; i--) {
		ans += uniqueNum[i] * (1 << (Size - i - 1));
	}
	cout << ans;
	return 0;
}