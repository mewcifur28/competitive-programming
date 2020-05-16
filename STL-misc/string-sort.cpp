/*
Nishant is a very naughty boy in Launchpad Batch.
One day he was playing with strings, and randomly shuffled them all.
Your task is to help Nishant Sort all the strings ( lexicographically ), 
but if a string is present completely as a prefix in another string, 
then string with longer length should come first. 
Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat
*/
#include<bits/stdc++.h>
using namespace std;
bool mycomp(string a, string b) {
	if (a.find(b) == string::npos && b.find(a) == string::npos) {
		return a < b;
	}
	return a.length() > b.length();
}
int main() {
	int n;
	cin >> n;
	vector<string> strings(n);
	for (int i = 0; i < n; i++) {
		cin >> strings[i];
	}
	sort(strings.begin(), strings.end(), mycomp);
	for (int i = 0; i < n; i++) {
		cout << strings[i] << endl;
	}
	return 0;
}