// https://www.spoj.com/problems/BALIFE/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    while (1) {
        ll n;
        cin >> n;
        if (n == -1) {
            break;
        }
        vector<ll> jobs(n);
        ll reqdLoad = 0, numOfRounds = -1;
        for (int i = 0; i < n; i++) {
            cin >> jobs[i];
            reqdLoad += jobs[i];
        }
        if (reqdLoad % n != 0) {
            cout << numOfRounds << "\n";
            continue;
        }
        ll leftSum = jobs[0];
        reqdLoad /= n, numOfRounds = 0;
        //create partitions and find ans for each partition
        for (int i = 0; i < n-1; i++) {
            ll shouldHave = (i+1)*reqdLoad;
            ll diff = abs(leftSum - shouldHave);
            numOfRounds = max(numOfRounds, diff);
            leftSum += jobs[i+1];
        }
        cout << numOfRounds << "\n";
    }
    return 0;
}
