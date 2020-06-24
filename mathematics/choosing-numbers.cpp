/*
N students are asked to choose a number from 1 to 100 inclusive. What is the expected number of students that would choose a single digit number?

Input Format
An integer n denoting number of students

Constraints
Output Format
A float denoting the answer upto 2 decimal point accuracy

Sample Input
8
Sample Output
0.72
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	cout << fixed << setprecision(2) << (n * 9.0) / 100;
	return 0;
}