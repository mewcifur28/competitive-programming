/*
Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing atmost K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> perm(n), pos(n+1, 0);
	for (int i = 0; i < n; i++) {
		cin >> perm[i];
		pos[perm[i]] = i + 1;
	}
	/*for (int i = 0; i <= n; i++) {
		cout << pos[i] << " ";
	}*/
	//max -> pos,,, i -> perm
	for (int max = n, i = 0, swaps = 0; max > 0 && i < n && swaps < k; max--, i++) {
		int maxpos = pos[max];
		if (perm[i] != max) {
			swap(perm[i], perm[maxpos - 1]);
			pos[max] = i + 1;
			pos[perm[maxpos - 1]] = maxpos;
			swaps++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << perm[i] << " ";
	}
	return 0;
}