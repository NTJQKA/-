//P1966 [NOIP 2013 提高组] 火柴排队
//可以优化，但是暂时懒得写了，今天太累了
//今天睡前还有个任务：整理归并排序和归并分治板子，并结合逆序对背景（线代）仔细回顾下今天所学
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;
const int mod = 1e8 - 3;
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
    cin>>n;
    vector<int> a(n), b(n);
    for (auto &elem : a) cin>>elem;
    for (auto &elem : b) cin>>elem;
    vector<int> a1 = a, b1 = b;//建立映射用的辅助数组
    map<int, int> Map1, Map2;//a b 中第几个元素第几大的映射
    sort(a1.begin(), a1.end()), sort(b1.begin(), b1.end());
    for (int i = 0; i < n; ++i) Map1[a1[i]] = i, Map2[b1[i]] = i;
    vector<int> a2(n), b2(n);
    for (int i = 0; i < n; ++i) a2[i] = Map1[a[i]], b2[i] = Map2[b[i]];
    map<int, int> Map3;
    for (int i = 0; i < n; ++i) Map3[b2[i]] = i;
    vector<int> tar(n);
    for (int i = 0; i < n; ++i) tar[i] = Map3[a2[i]];
    i64 ans = solve(tar, 0, n - 1);
    cout<<ans % mod<<endl;
    system("pause");
}