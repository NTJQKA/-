//P1908 逆序对
//删去goto改为单独封装cross函数并提前return，同时使得merge函数不需要做内部调整，拿起板子就可以用
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
i64 cross(vector<int> &a, int l, int mid, int r) {
    i64 ret = 0;
    for (int i = mid + 1, j = l; i <= r; ++i) {
        while (a[j] <= a[i]) {
            if (j == mid) return ret;
            j++;
        }
        ret += mid - j + 1;
    }
    return ret;
}
void merge(vector<int> &a, int l, int mid, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1;//左右两个区间的起始指针
    for (int k = 0; k < tmp.size(); ++k) {
        if (i == mid + 1) tmp[k] = a[j++];//注意条件是要指针越界，即a.end()，指向最后一个位置是不可以的，下面j同理
        else if (j == r + 1) tmp[k] = a[i++];
        else a[i] <= a[j] ? tmp[k] = a[i++] : tmp[k] = a[j++];
    }
    for (auto elem : tmp) a[l++] = elem;
}
i64 solve(vector<int> &a, int l, int r) {
    if (l == r) return 0;
    int mid = l + (r - l) / 2;
    i64 ret = solve(a, l, mid) + solve(a, mid + 1, r) + cross(a, l, mid, r);
    merge(a, l, mid, r);
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    i64 ans = solve(a, 0, n - 1);
    cout<<ans<<endl;
    system("pause");
}