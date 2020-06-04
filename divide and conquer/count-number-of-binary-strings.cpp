/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/
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
	while (T--) {
		int n;
		cin >> n;
        vector<long long int> mem(n+1, -1);
		cout << binStr(n, mem) << "\n";
	}
	return 0;
}