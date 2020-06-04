/*
Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(())
*/
#include<bits/stdc++.h>
using namespace std;
void generateParanthesis(int n, string s, int open, int close) {
	if (s.length() == 2*n) {
		cout << s << endl;
		return;
	}
	if (close < open) {
		generateParanthesis(n, s + ")", open, close + 1);
	}
	if (open < n) {
		generateParanthesis(n, s + "(", open + 1, close);
	}
}
int main() {
	int n;
	cin >> n;
	generateParanthesis(n, "", 0, 0);
	return 0;
}