//P1824 进击的奶牛
//这个题看似二分答案思想，实则枚举答案的思想。二分搜索只不过是平均/期望次数比较小的枚举而已，是优化手段
//即使答案落在int这么大的区间里，也是有枚举答案/二分搜索答案的可能的
//感觉除了枚举答案思想以外，check函数里面维护指针的逻辑也很容易写错，第一遍想了好久，还是值得优化一下，以后再看看的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
bool check(vector<int> &b, int ans) {
    int ptr = 1;
    int possibile_cow_num = 1;//b[0]肯定是0，左端点也一定会放一只，下面ptr就不从0开始了
    while (ptr != n) {
        int sum = 0;
        while (ptr != n && sum < ans) {
            sum += b[ptr];
            ptr++;
        }
        if (sum < ans) break;//如果从上面while出来还能满足sum < ans，说明ptr到n了；而到最后也没能符合区间长度要求，直接break
        else possibile_cow_num++;
    }
    return possibile_cow_num >= c;
}
int main() {
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());

    vector<int> b(n);//差分数组，因为相邻区间间隔长度总是被计算，不如存起来
    for (int i = 1; i < n; ++i) b[i] = a[i] - a[i-1];

    int l = 1, r = a[n-1] - a[0];
    while (l != r) {
        int m = l + (r - l + 1) / 2;
        if (check(b, m) == true) l = m;
        else r = m - 1;
    }
    cout<<l<<endl;
    system("pause");
}