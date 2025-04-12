//本地跑第二个点跑了一分钟，证实了答案正确，纯超时，跑了将近3.5min
//这样最坏原始时间复杂度是nlogn + 2nlogn，常数可能太大了，
//要么试试STL lowerbound upperbound优化，要么试试数据处理部分试试指针维护而不是二分，变成o(nlogn + n)
//STL二分函数跑了差不多1s。难道我的二分函数速度很慢？？？
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, c;
ll ans;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + c;
        int target;
        auto l = lower_bound(a.begin(), a.end(), b[i]);
        auto r = upper_bound(a.begin(), a.end(), b[i]);
        ans += r - l;
        auto l = lower_bound(a.begin(), a.end(), target);
        auto r = upper_bound(a.begin(), a.end(), target);
        ans += r - l;
        //注意二分查找函数是完全迭代器兼容的（我自己取的名），upperbound找的是第一个大于目标数的元素的迭代器，而不是最后一个合题元素，所以底下不用-1
    }
    cout<<ans<<endl;
    system("pause");
}