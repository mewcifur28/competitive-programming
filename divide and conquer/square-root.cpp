#include<bits/stdc++.h>
using namespace std;
float squareRoot(float num, int p) {
    int s = 0, e = num, intVal = 0;
    while (s <= e) {
        int m = s + (e-s)/2;
        if (m*m == num) {
            intVal = m;
            break;
        }
        else if (m*m < num){
            intVal = m;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    float precision = 0.1, ans = intVal;
    for (int i = 0; i < p; i++) {
        while (ans*ans <= num) {
            ans += precision;
        }
        ans -= precision;
        precision /= 10;
    }
    return ans;
}
int main() {
    float num;
    cin >> num;
    int p;
    cin >> p;
    cout << squareRoot(num, p);
    return 0;
}