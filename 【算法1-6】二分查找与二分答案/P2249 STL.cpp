//P2249 【深基13.例1】查找
//比手写二分一共慢了3ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    int target = 0;
    while (m--) {
        cin>>target;
        auto iter = lower_bound(a.begin(), a.end(), target);
        int pos = iter - a.begin();
        if (pos == n || target != a[pos]) cout<<-1<<" ";
        else cout<<pos + 1<<" ";//+1是因为本题要求下标从1开始编号
    }
    system("pause");
}