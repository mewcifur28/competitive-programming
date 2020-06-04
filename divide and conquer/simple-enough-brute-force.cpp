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