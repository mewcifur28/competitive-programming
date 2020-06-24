// What is the expected number of coin flips for getting N consecutive heads, given the value of N? Say N = 1, expected number of throws to get 1 head will be 2.

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	ll n;
	cin >> n;
	cout << pow(2, n+1) - 2;
	return 0;
}