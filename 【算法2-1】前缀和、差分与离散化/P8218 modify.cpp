//P8218 【深进1.例1】求区间和
//涉及前缀和时候，an和sn数组最好都开成n + 1的，这样在算区间和时不用考虑l - 1下标为0越界问题，即不加边界判断地使用A[r] - A[l - 1]公式
#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
    cin>>n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    vector<int> A(n + 1);
    partial_sum(a.begin(), a.end(), A.begin());
    cin>>m;
    while (m--) {
        int l = 0, r = 0; cin>>l>>r;
        cout<<A[r] - A[l - 1]<<endl;
    }
}