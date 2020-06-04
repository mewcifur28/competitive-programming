/*For a given number n, form a list and insert the following pattern into the list at the same position sequentially.
{floor(n/2) , n%2 , floor(n/2) }
Until every element in the list is either 1 or 0. Now, calculate number of 1s in from l to r (1-indexed).

EXPLAINATION: Start from n. Then make a list with the following elements.i.e. {floor(n/2) , n%2 , floor(n/2) }. Now this list has three elements. Now further break down each of those 3 elements considering the new n to be floor(n/2) , n%2 and floor(n/2) respectively for those three elements respectively INPLACE. And this process will go on until the n reduces down to 1 or 0. So it will basically form a tree with 3 branches coming out of every node at every level starting from 1 node (n) at the root.
Input Format
Three integers n , l , r

Constraints
0 ≤ n < 10^12, 0 ≤ r - l ≤ 10^6, 1 ≤ l ≤ r

Output Format
Single line containing number of 1s in the given range.

Sample Input
9 6 9
Sample Output
3
Explanation
9 will have the sequence : 101010111010101*/

// Solution gave MLE, efficient soln given
#include<bits/stdc++.h>
using namespace std;
vector<int> sequence, temp;
int main() {
    int n, l, r;
    cin >> n >> l >> r;
    sequence.push_back(n/2);
    sequence.push_back(n%2);
    sequence.push_back(n/2);
    bool isAllOneOrZero = true;
    for (int i = 0; i < sequence.size() && isAllOneOrZero; i++) {
        if (!(sequence[i] == 0 || sequence[i] == 1)) {
            isAllOneOrZero = false;
        }
    }
    while (!isAllOneOrZero) {
        temp.clear();
        isAllOneOrZero = true;
        for (int i = 0; i < sequence.size(); i++) {
            if (sequence[i] == 1 || sequence[i] == 0) {
                temp.push_back(sequence[i]);
                continue;
            }
            int val1 = sequence[i] / 2, val2 = sequence[i] % 2;
            temp.push_back(val1);
            temp.push_back(val2);
            temp.push_back(val1);
            if (!(val1 == 0 || val1 == 1)) {
                isAllOneOrZero = false;
            }
            if (!(val2 == 0 || val2 == 1)) {
                isAllOneOrZero = false;
            }
        }
        sequence = temp;
    }
    int count = 0;
    for (int i = l - 1; i <= r - 1; i++) {
        if (sequence[i] == 1) {
            count++;
        }
    }
    cout << count;
    return 0;
}