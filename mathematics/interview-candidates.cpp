/*
Candidates are appearing for interview one after other. Probability of each candidate getting selected is 0.16. What is the expected number of candidates that you will need to interview to make sure that you select somebody?
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	float p = 0.16;
	cout << ceil(1/p);
	return 0;
}