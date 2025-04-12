//P8218 【深进1.例1】求区间和
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    vector<int> A(n);
    A[0] = a[0];
    for (int i = 1; i < n; ++i) {
        A[i] = A[i - 1] + a[i];
    }
    cin>>m;
    while (m--) {
        int l, r; cin>>l>>r;
        l--, r--;
        if (l - 1 < 0) {
            cout<<A[r]<<endl;
            continue;
        }
        cout<<A[r] - A[l - 1]<<endl;
    }
    system("pause");
}