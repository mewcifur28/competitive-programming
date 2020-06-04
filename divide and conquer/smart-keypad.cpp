/*
You will be given a numeric string S. Print all the possible codes for S.

Following vector contains the codes corresponding to the digits mapped.

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

For example, string corresponding to 0 is " " and 1 is ".+@$"

Input Format
A single string containing numbers only.

Constraints
length of string <= 10

Output Format
All possible codes one per line in the following order.

The letter that appears first in the code should come first

Sample Input
12
Sample Output
.a
.b
.c
+a
+b
+c
@a
@b
@c
$a
$b
$c
Explanation
For code 1 the corresponding string is .+@$ and abc corresponds to code 2.
*/
#include<bits/stdc++.h>
using namespace std;
vector<string> keypad = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void printCodes(string digits, int index = 0, string out = "") {
	if (index >= digits.length()) {
		cout << out << "\n";
		return;
	}
	int digit = digits[index] - '0';
	for (int i = 0; i < keypad[digit].length(); i++) {
		printCodes(digits, index + 1, out + keypad[digit][i]);
	}
}
int main() {
	string digits;
	cin >> digits;
	printCodes(digits);
	return 0;
}