/*
We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.

Input Format
We are given two integers x and y

Constraints
l <= r <= 1000

Output Format
Print the maximum value of a XOR b

Sample Input
5
6
Sample Output
3
Explanation
If a and b are taken to be 5. Then a xor b = 0
If a and b are taken to be 6. Then a xor b = 0
If a is 5 and b is 6. Then a xor b is 3.


*/

#include<bits/stdc++.h>
using namespace std;
int main () {
	int x, y;
	cin >> x >> y;
	int XOR = x^y;
	int j = 0;
	for (; XOR; j++) {
		XOR = XOR >> 1;
	}
	j--;
	int ans = 0;
	for (int i = 0; i <= j; i++) {
		ans = ans | 1;
		ans = ans << 1;
	}
	cout << (ans >> 1);
	return 0;
}