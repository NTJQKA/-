//P5076 【深基16.例7】普通二叉树（简化版）
//case 4忘记写break了，查错查了30分钟。。
//据说set也能做，我用vector + lower_bound了，最大开销在insert，有空看下标准解法
#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void solve(int opt, int x) {
    switch (opt) {
        case 1 : cout<<lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1<<endl; break;
        case 2 : cout<<vec[x - 1]<<endl; break;
        case 3 : {
            auto p = lower_bound(vec.begin(), vec.end(), x);
            if (p == vec.begin()) cout<<-INT_MAX<<endl;
            else cout<<*--p<<endl;
            break;
        }
        case 4 : {
            auto p = upper_bound(vec.begin(), vec.end(), x);
            if (p == vec.end()) cout<<INT_MAX<<endl;
            else cout<<*p<<endl;
            break;
        }
        case 5 : {
            auto p = lower_bound(vec.begin(), vec.end(), x);
            vec.insert(p, x);
            break;
        }
    }
}
int main() {
    freopen("P5076_1.in", "r", stdin);
    int q = 0;
    cin>>q;
    while (q--) {
        int opt = 0, x = 0;
        cin>>opt>>x;
        solve(opt, x);
    }
    freopen("CON", "r", stdin);
    system("pause");
}