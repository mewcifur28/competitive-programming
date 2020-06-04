/*
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2
*/
#include<bits/stdc++.h>
using namespace std;
long long int tiles(long long int n, long long int m, vector<long long int> &mem) {
	if (mem[n] != -1) {
		return mem[n];
	}
	if (n == m) {
		mem[n] = 2;
		return 2;
	}
	if (n < m && n > 0) {
		mem[n] = 1;
		return 1;
	}
	if (n <= 0) {
		return 0;
	}
	mem[n] = ((tiles(n-1, m, mem) % 1000000007) + (tiles(n-m, m, mem) % 1000000007)) % 1000000007;
	return mem[n];
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int n, m;
		cin >> n >> m;
		vector<long long int> mem(n+1, -1);
		cout << tiles(n, m, mem) << endl;
	}
	return 0;
}