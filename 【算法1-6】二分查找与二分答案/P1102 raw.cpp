//本地跑第二个点跑了一分钟，证实了答案正确，纯超时，跑了将近3.5min
//询问deepseek结果：传数组时候如果不是引用形式会进行传值，例如传长度为n的数组，在传值上开销就是o(n)，这是不能接受的。传引用是传一个指针，o(1)
//此外，还可以通过inline内联（编译器不一定接受内联建议！但是STL由于规定了实现方式，是一定内联的），cin.tie(nullptr)等方式进一步加速
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int n, c;
ll ans;
inline int find(vector<int> &a, int target, int l, int r) {
    while (l != r) {
        int m = l + (r - l) / 2;
        if (a[m] >= target) r = m;
        else l = m + 1;
    }
    if (a[l] == target) return l;
    else return -1;
}
inline int rfind(vector<int> &a, int target, int l, int r) {
    while (l != r) {
        int m = l + (r - l + 1) / 2;
        if (a[m] <= target) l = m;
        else r = m - 1;
    }
    if (a[l] == target) return l;
    else return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>c;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    vector<int> b(n);
    for (auto elem : a) {
        int target = elem + c;
        int flag = find(a, target, 0, n-1);
        if (flag != -1) {
            int last = rfind(a, target, flag, n-1);
            ans += last - flag + 1;
        }//这个要优化的话可以用lower_bound upper_bound那种兼容方式来处理，那样的话若无返回.end()，不用加逻辑判断，节省大脑逻辑处理时间
    }
    cout<<ans<<endl;
    system("pause");
}