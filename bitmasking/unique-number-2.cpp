#include<bits/stdc++.h>
using namespace std;
bool hasSetBit(int n, int i) {
	//create mask
	int mask = 1 >> i;
	n = mask & n;
	return n > 0;
}
int main() {
	int n, result = 0, a = 0, b = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		result = result ^ v[i];
	}
	//find position of first set bit in result
	int pos = 0, temp = result;
	while (temp & 1 == 0) {
		temp = temp >> 1;
		pos++;
	}
	for (int i = 0; i < n; i++) {
		if (hasSetBit(v[i], pos)) {
			a = a ^ v[i];
		}
	}
	b = result ^ a;
	if (a > b) {
		swap(a, b);
	}
	cout << a << " " << b;
	return 0;
}