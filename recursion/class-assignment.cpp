//same problem as count-number-of-binary-strings

#include<bits/stdc++.h>
using namespace std;
long long int binStr(int n, vector<long long int> &mem) {
    if (mem[n] != -1) {
        return mem[n];
    }
	if (n <= 0) {
		return 0;
	}
	if (n == 1) {
        mem[n] = 2;
		return 2;
	}
	if (n == 2) {
        mem[n] = 3;
		return 3;
	}
	mem[n] = binStr(n-1, mem) + binStr(n-2, mem);
    return mem[n];
}
int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int n;
		cin >> n;
        vector<long long int> mem(n+1, -1);
		cout << "#" << i << " : " << binStr(n, mem) << "\n";
	}
	return 0;
}