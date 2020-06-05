/*
You are given N books, ith of which has Pi pages (Pi <= Pj, if i < j). You have to assign these N books to M students, such that each student has subsegment of books and the maximum number of pages assigned to a student is minimized.
You have to find the maximum number of pages, a student can have in this assignment of books.

Input Format
First line contains integers, N and M, denoting the number of books and number of students respectively. Next line contains N integers, denoting the number of pages in N books.

Constraints
1<=N<=10^5 1<=M<=N 1<=Pi<=10^9

Output Format
Print a single integer, denoting the answer.

Sample Input
4 2
10 20 30 40
Sample Output
60
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isValid(ll books, ll studentsGiven, vector<ll> &pages, ll pageLimit) {
    ll studentsNeeded = 1, pagesReadByCurrStudent = pages[0];
    if (pages[0] > pageLimit) {
        return false;
    }
    for (int i = 1; i < books; i++) {
        if (pages[i] > pageLimit) {
            return false;
        }
        if (pagesReadByCurrStudent + pages[i] > pageLimit) {
            studentsNeeded++;
            pagesReadByCurrStudent = 0;
            i--;
        }
        else {
            pagesReadByCurrStudent += pages[i];
        }
    }
    return studentsGiven >= studentsNeeded;
}
ll findMaxPages(ll books, ll students, vector<ll> &pages, ll s, ll e, ll sum) {
    ll pagesRead = e;
    while (s <= e) {
        ll m = s + (e-s)/2;
        if (isValid(books, students, pages, m)) {
            pagesRead = m;
            e = m-1;
        }
        else {
            s = m+1;
        }
    }
    return pagesRead;
}
int main() {
    ll books, students, sum = 0;
    cin >> books >> students;
    vector<ll> pages(books);
    for (ll i = 0; i < books; i++) {
        cin >> pages[i];
        sum += pages[i];
    }
    cout << findMaxPages(books, students, pages, 0, sum, sum);
    return 0;
}