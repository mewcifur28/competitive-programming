/*
The coding blocks members went to the success party of their first ever online boot-camp at Murthal. They ordered P number of paranthas. The stall has L cooks and each cook has a rank R. A cook with a rank R can cook 1 parantha in the first R minutes 1 more parantha in the next 2R minutes, 1 more parantha in 3R minutes and so on(he can only cook a complete parantha) ( For example if a cook is ranked 2.. he will cook one parantha in 2 minutes one more parantha in the next 4 mins and one more in the next 6 minutes hence in total 12 minutes he cooks 3 paranthas. In 13 minutes also he can cook only 3 paranthas as he does not have enough time for the 4th parantha). Calculate the minimum time needed to cook all the paranthas.

Input Format
First line contains P, the number of pratha ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the Next line each denoting the rank of a cook.

Constraints
P <= 1000
L <= 50
1 <= R <= 8

Output Format
Print an integer which tells the number of minutes needed to get the order done.

Sample Input
10
4 
1 2 3 4
Sample Output
12
Explanation
First cook with rank 1 cooks 4 paranthas in 10 minutes (1+2+3+4).
Second cook with rank 2 cooks 3 paranthas in 12 minutes (2+4+6)
Third cook with rank 3 cooks 2 paranthas in 9 minutes (3+6) Fourth cook with rank 4 only needs to cook one last remaining parantha. He can do that in 4 minutes.
Since these cooks cook parallely, the total time taken will be the maximum of the four i.e. 12 minutes.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isEnoughTime(ll parantheRequired, ll numOfCooks, vector<ll> &ranks, ll timeTaken) {
    ll parantheCooked = 0;
    for (ll i = 0; i < numOfCooks; i++) {
        int x = 0;
        while (((x) * (x + 1) * ranks[i])/2 <= timeTaken) {
            x++;
        }
        x--;
        parantheCooked += x;
    }
    return parantheCooked >= parantheRequired;
}
ll calcTime(ll numOfParanthe, ll numOfCooks, vector<ll> &ranks) {
    ll s = 0, e = (numOfParanthe) * (numOfParanthe + 1) * ranks[numOfCooks - 1];
    ll timeTaken = e;
    while (s <= e) {
        ll m = s + (e - s)/2;
        if (isEnoughTime(numOfParanthe, numOfCooks, ranks, m)) {
            timeTaken = m;
            //cout << s << " " << e << " " << timeTaken << "\n";
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return timeTaken;
}
int main() {
    ll numOfParanthe, numOfCooks;
    cin >> numOfParanthe >> numOfCooks;
    vector<ll> ranks(numOfCooks);
    for (ll i = 0; i < numOfCooks; i++) {
        cin >> ranks[i];
    }
    sort(ranks.begin(), ranks.end());
    cout << calcTime(numOfParanthe, numOfCooks, ranks);
    return 0;
}