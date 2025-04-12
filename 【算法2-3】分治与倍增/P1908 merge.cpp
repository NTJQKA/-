//P1908 逆序对
//n bound : 5 * 1e5 ; C(n, 2) bound : 124999750000
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n;
i64 merge(vector<int> &a, int l, int mid, int r) {//才发现STL里面有个merge，但是这里还是用手写的了，STL那个接入需要迭代器
    //notice : when arrived at this function, both the left array and the right array has already been sorted;
    i64 ret = 0;
    for (int i = mid + 1, j = l; i <= r; ++i) {//注意：j = l, 不是0！！！本题程序中l r都是相对于原a数组的，是相对位置
        while (a[j] <= a[i]) {
            if (j == mid) goto finish_ret;
            j++;
        }
        ret += mid - j + 1;
    }
    finish_ret:
    //notice : going to merge now
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1;//左右两个区间的起始指针
    for (int k = 0; k < tmp.size(); ++k) {
        if (i == mid + 1) tmp[k] = a[j++];//注意条件是要指针越界，即a.end()，指向最后一个位置是不可以的，下面j同理
        else if (j == r + 1) tmp[k] = a[i++];
        else a[i] <= a[j] ? tmp[k] = a[i++] : tmp[k] = a[j++];
    }
    for (auto elem : tmp) a[l++] = elem;
    //notice : return calculated ans here, because we can't return ans right after calculation
    return ret;
}
i64 solve(vector<int> &a, int l, int r) {
    if (l == r) return 0;
    int mid = l + (r - l) / 2;
    return solve(a, l, mid) + solve(a, mid + 1, r) + merge(a, l, mid, r);
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