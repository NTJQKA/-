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
    int l = 0, r = 0;//注意初始化在for外面，这也是指针维护的精髓
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] + c;
        while (l < n && a[l] < b[i]) l++;
        while (r < n && a[r] <= b[i]) r++;
        ans += r - l;
    }
    cout<<ans<<endl;
    system("pause");
}