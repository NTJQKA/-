//P2842 纸币问题 1
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int main() {
    int n, w;
    cin>>n>>w;
    vector<int> a(n);//, dp(w + 1);
    vector<vector<int>> dp(n, vector<int>(w + 1));
    for (auto &elem : a) cin>>elem;

    for (int i = 0; i <= w; ++i) {
        dp[0][i] = ceil(w / a[0]);
    }//初始化

    /*for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= w; ++j) {
            int k_max = j / a[i];
            int minv = INT_MAX;
            for (int k = 0; k <= k_max; ++k) {
                minv = min(minv, dp[i - 1][j - k * a[i]] + k);
            }
            dp[i][j] = minv;
        }
    }*///刚学完01背包，把自己思路整繁琐了，实际上这个题只需要一个维，且状态转移很直观，拿一张纸币，然后询问减去这张纸币后剩余所需的面额的最小值即可
    cout<<dp[n - 1][w]<<endl;
    system("pause");
}