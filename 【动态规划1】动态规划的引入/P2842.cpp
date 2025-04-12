//P2842 纸币问题 1
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int main() {
    int n, w;
    cin>>n>>w;
    vector<int> a(n), dp(w + 1);
    for (auto &elem : a) cin>>elem;
    for (auto &elem : dp) elem = /*INT_MAX*/1e9;
    //这里有一个很坑的点：INT_MAX会出问题，因为下面语句中使用了dp[] + 1，有可能导致出现-1，而-1是会一直占用minv的位置的
    dp[0] = 0;
    for (int i = 1; i <= w; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout<<dp[w]<<endl;
    system("pause");
}