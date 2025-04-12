//P2840 纸币问题 2
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
    dp[0] = 1;
    for (int i = 1; i <= w; ++i) {//i是要凑的金额
        for (int j = 0; j < n; ++j) {//j是最后一张要用的纸币
            if (i - a[j] >= 0) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }//状态转移式子是个sigma，转化为C语言后是递推 +=，如果没做过这题，程序可读性还真不好
    }
    cout<<dp[w]<<endl;
    system("pause");
}