/*
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. Write a recursive function (return type Arraylist) to print all possible codes for the string. E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]
*/
#include<bits/stdc++.h>
using namespace std;
void printCodes(string digits, vector<string> &codes, int index = 0, string out = "") {
	if (index >= digits.length()) {
		codes.push_back(out);
		return;
	}
	//include only the current number
	int digit = digits[index] - '0';
	if (digit != 0) {
		//cout << digit << " ";
		printCodes(digits, codes, index + 1, out + char(digit + 'a' - 1));
	}
	//include 2 numbers
	if (index < digits.length() - 1) {
		string digitstr = "";
		digitstr += digits[index];
		digitstr += digits[index + 1];
		digit = stoi(digitstr);
		if (digit <= 26) {
			//cout << digit << " ";
			printCodes(digits, codes, index + 2, out + char(digit + 'a' - 1));
		}
	}
}
int main() {
	string digits;
	cin >> digits;
    vector<string> codes;
	cout << "[";
	printCodes(digits, codes);
    for (int i = 0; i < codes.size() - 1; i++) {
        cout << codes[i] << ", ";
    }
    cout << codes[codes.size() - 1] << "]";
	return 0;
}