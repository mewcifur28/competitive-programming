/*
Rahul had a sorted array of numbers from which he had to find a given number quickly. His friend by mistake rotated the array. Now Rahul doesn't have time to sort the elements again. Help him to quickly find the given number from the rotated array.

Hint - Think Binary Search!

Input Format
The first line contains N - the size of the array. the next N lines contain the numbers of the array.The next line contains the item to be searched.

Constraints
Output Format
Output the index of number in the array to be searched. Output -1 if the number is not found.

Sample Input
5
4
5
1
2
3
2
Sample Output
3
Explanation
The given rotated array is [4, 5, 1, 2, 3]. The element to be searched is 2 whose index is 3.
*/
#include<bits/stdc++.h>
using namespace std;
int bSearch(vector<int> &v, int s, int e, int key) {
    if (s > e) {
        return -1;
    }
    int mid = s + (e - s)/2;
    if (key == v[mid]) {
        return mid;
    }
    if (v[s] <= v[mid]) {
        if (key > v[s] && key < v[mid]) {
            return bSearch(v, s, mid-1, key);
        }
        else {
            return bSearch(v, mid+1, e, key);
        }
    }
    else if (v[mid] <= v[e]) {
        if (key > v[mid] && key < v[e]) {
            return bSearch(v, mid+1, e, key);
        }
        else {
            return bSearch(v, s, mid-1, key);
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
    int key;
    cin >> key;
    cout << bSearch(v, 0, n - 1, key);
    return 0;
}