#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int partition(vector<ll> &v, int s, int e) {
    ll pivot = v[e];
    int i = s-1, j = s;
    for (; j < e; j++) {
        if (v[j] <= pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[e]);
    return i+1;
}
void quickSort(vector<ll> &v, int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition(v, s, e);
    quickSort(v, s, p-1);
    quickSort(v, p+1, e);
}
int main() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    quickSort(v, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}