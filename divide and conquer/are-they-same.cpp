/*
This year when tourist visited India for codsule 2019. He and Rajat started discussing few problems on divide and conquer. tourist asked Rajat that if you have 2 strings s1 and s2 can you find if they are equivalent. Rajat then asked the condition for being equivalent to which tourist replied

Two strings a and b of equal length are called equivalent in one of the two cases:

They are equal.
If we split string a into two halves of the same size a1 and a2, and string b into two halves of the same size b1 and b2, then one of the following is correct:
a1 is equivalent to b1, and a2 is equivalent to b2
a1 is equivalent to b2, and a2 is equivalent to b1
Rajat quickly solved the problem can you?

Input Format
First line is number of test cases t Then follow two strings each of same length

Constraints
1 <= test cases <= 10 1 <= string length <= 50000

Output Format
print "YES" if they are "equivalent" and "NO" if they are not

Sample Input
3
ababa
baaba
ab
ba
abc
abc
Sample Output
NO
YES
YES
Explanation
test case 1 : - you cannot split the string into two halves of same size and s1 != s2 hence they are not same test case 2 :- split ab as a and b and ba as b and a then conditon is fulfilled test case 3 :- they are already same
*/
#include <bits/stdc++.h>
using namespace std;
bool isEquivalent(string a, string b) {
    if (a.length() != b.length()) {
        return false;
    }
    if (a == b) {
        return true;
    }
    int len = a.length();
    if (len == 0) {
        return true;
    }
    if (len & 1 == 1) {
        return false;
    }
    string a1 = a.substr(0, len/2), a2 = a.substr(len/2), b1 = b.substr(0, len/2), b2 = b.substr(len/2);
    return ((isEquivalent(a1, b1) && isEquivalent(a2, b2)) || (isEquivalent(a1, b2) && isEquivalent(a2, b1)));
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        isEquivalent(s1, s2) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
