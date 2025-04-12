//P4017 最大食物链计数
//本题没说A < B，所以最好别顺序dp了，记搜一下吧
//80112002
#include <bits/stdc++.h>
#define vecprt(x) for (auto elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
using i64 = long long;
int n, m;
vector<i64> dp;
vector<bool> vis;
vector<vector<bool>> mp;
void get_dp(int i) {
    i64 sum = 0;
    for (int j = 1; j <= n; ++j) {
        if (mp[j][i]) {
            if (!vis[j]) {
                get_dp(j);
                vis[j] = true;
            }
            sum += dp[j];
        }
    }
    if (sum == 0) sum = 1;
    //dp[i] = sum;
    dp[i] = sum % 80112002;
    vis[i] = true;
}
int main() {
    cin>>n>>m;
    dp.resize(n + 1), vis.resize(n + 1), mp.resize(n + 1);
    for (auto &row : mp) row.resize(n + 1);
    while (m--) {
        int u = 0, v = 0;
        cin>>u>>v;
        mp[u][v] = true;
    }
    /*for (int i = 0; i <= n; ++i) {
        mp[0][i] = true, mp[i][0] = true;
    }*/
    /*for (auto row : mp) {
        vecprt(row);
    } cout<<endl;*/

    //get true! get initial 1
    /*for (int j = 1; j <= n; ++j) {
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            if (mp[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            dp[j] = 1;
            vis[j] = true;
        }
    }*/

    //get all dp value
    //dp[0] = 1, vis[0] = true;
    for (int i = 1; i <= n; ++i) {
        /*cout<<"round"<<i<<" : ";
        vecprt(dp);*/
        get_dp(i);
    }
    //vecprt(dp);
    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (auto elem : mp[i]) {
            if (elem) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            ans += dp[i];
        }
    }
    cout<<ans % 80112002<<endl;
    system("pause");
}