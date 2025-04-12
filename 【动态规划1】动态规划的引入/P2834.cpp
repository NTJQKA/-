//P2834 纸币问题 3
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;
int n, w;
int main() {
    cin>>n>>w;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    vector<i64> dp(w + 1);
    /*for (int i = 0; i <= w; ++i) {
        i % a[0] == 0 ? dp[i] = 1 : dp[i] = 0;
    }*///initialize
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {//用前i张纸币
        for (int j = 0; j <= w; ++j) {
            //int k_bound = j / a[i];
            /*for (int k = k_bound; k >= 0; --k) {
                dp[j] = 
            }*/
            //dp[j] = k_bound * dp[j - k_bound * a[i]]; k_bound = 0时有问题
            //经过优化和推导，可以得到以下式子
            if (j - a[i] >= 0) dp[j] += dp[j - a[i]] % mod;
            //二维：
            //if (j - a[i] >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
            //else dp[i][j] = dp[i - 1][j];
            //i从0到n枚举，j从0到w枚举，即可压维并省去else
        }
    }
    dp[w] %= mod;//剩余系分析知识，如果上面写成了+=取模形式，最后这里要补一个%=的
    cout<<dp[w]<<endl;
    system("pause");
}