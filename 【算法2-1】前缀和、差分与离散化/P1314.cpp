//P1314 [NOIP 2011 提高组] 聪明的质监员
//实际上这个题细节很多，看似只有二分和一维前缀和，但是前者涉及一个最优解保存（二分变式），后者需要存两个变量的前缀和（bool 是否合格, int 价值之和），
//这不容易想，而且区间中有的合格有的不合格也容易让人认为情况很离散，放弃前缀和。实际上，只要是涉及某个连续区间上“符合特征的元素个数”“符合特征的元素之和”的问题都可以前缀和。最简单的版本就是区间内元素全部符合特征，进行区间简单求和
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n, m;
i64 s, ans = 1e12;//luogu compile error with _I64_MAX
vector<int> w, v;//weight, value
vector<pair<int, int>> range;
i64 get_d(int W) {//d : s - y
    vector<int> sw(n + 1), sv(n + 1);
    for (int i = 1; i <= n; ++i) {//O(n) make table
        sw[i] = sw[i - 1], sv[i] = sv[i - 1];
        if (w[i] >= W) sw[i]++, sv[i] += v[i];
    }
    i64 y = 0;
    for (auto &p : range) {//O(m) cauculate y = sigma(y[i]), O(1)for each
        int &l = p.first, &r = p.second;
        y += (sw[r] - sw[l - 1]) * (sv[r] - sv[l - 1]);
    }
    return s - y;
}
void binary_try_y() {
    vector<int> f = w;
    sort(f.begin(), f.end());
    f.push_back(f.back() + 1);//after push_back this, y could be 0
    // w len = n + 2
    int l = 0, r = n + 1;
    while (l != r) {
        int mid = (l + r) / 2;
        i64 d = get_d(f[mid]);
        if (d == 0) {//记录最优答案的二分，如果直接得到了理论上一定最优的答案可以直接break
            ans = 0;
            break;
        }
        ans = min(ans, abs(d));//逻辑优化，记录最优答案的二分，对最优答案的维护应该放在左移r或右移l前面
        if (d > 0) r = mid;
        else l = mid + 1;
    }
}
int main() {
    cin>>n>>m>>s;
    w.resize(n + 1), v.resize(n + 1), range.resize(m);
    for (int i = 1; i <= n; ++i) cin>>w[i]>>v[i];
    for (auto &elem : range) cin>>elem.first>>elem.second;
    binary_try_y();
    cout<<ans<<endl;
    system("pause");
}