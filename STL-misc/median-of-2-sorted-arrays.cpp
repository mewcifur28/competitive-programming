#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v1(n+1), v2(n+1);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	v1[n] = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> v2[i];
	}
	v2[n] = INT_MAX;
	//merge vectors
	vector<int> v3(2*n);
	int j = 0, k = 0;
	for (int i = 0; i < 2*n; i++) {
		v3[i] = v1[j] < v2[k] ? v1[j++] : v2[k++];
	}
	cout << v3[n-1] << endl;
	return 0;
}