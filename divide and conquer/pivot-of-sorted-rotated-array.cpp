/*
You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element in the array which is greater than its next element and divides the array into two monotonically increasing halves.

Input Format
The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

Constraints
Output Format
Output the index of the pivot of the array.

Sample Input
5
4
5
1
2
3
Sample Output
1
Explanation
Here, 5 is the pivot element. Thus the output is 1 which is 5's index.
*/
#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int> &v, int n) {
    int s = 0, e = n-1;
    while (s <= e) {
        int mid = (s+e) / 2;
        if ((mid < n-1) && v[mid] > v[mid + 1]) {
            return mid;
        }
        //left part is sorted, search in right
        else if (v[s] <= v[mid]) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << findPivot(v, n);
    return 0;
}