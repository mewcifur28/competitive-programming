/*
given probabilty p, find minimum number of people in a hall such that the probability of 2 people sharing their birthday = p.
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	float probability, num = 365.0, den = 365.0, x = 1.0;
	cin >> probability;
	if (probability == 1) {
		cout << "366";
	}
	else{
		int people = 0;
		while (x > 1 - probability) {
			x = (x * num) / den;
			people++;
			num = num - 1.0;
		}
		cout << people;
	}
	return 0;
}