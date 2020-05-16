/*
Prateek Bhayia likes to play with bits. One day Prateek bhayia decides to assign a task to his student Sanya. You have help Sanya to complete this task. Task is as follows - Prateek Bhayia gives Q queries each query containing two integers a and b. Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

Input Format
Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.

Constraints
Q,a,b are integers.

Output Format
Q lines, each containing an output for your query.

Sample Input
2
1 1
10 15
Sample Output
1
17
*/

#include<bits/stdc++.h>
using namespace std;
int setBits(int n) {
	int ans = 0;
	while (n) {
		n = n & (n-1);
		ans++;
	}
	return ans;
}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = a; i <= b; i++) {
			ans += setBits(i);
		}
		cout << ans << "\n";
	}
	return 0;
}