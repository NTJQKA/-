//P4017 最大食物链计数
//本题没说A < B，所以最好别顺序dp了，记搜一下吧
//这次改用DAG拓扑排序法，《深基》上的标答，确实好，相对于邻接矩阵空间和时间都更优
//80112002
#include <bits/stdc++.h>
#define vecprt(x) for (auto elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
using i64 = long long;
int n, m;
vector<i64> dp;
vector<vector<int>> mp;
vector<int> ind, outd;
int main() {
    cin>>n>>m;
    dp.resize(n + 1), ind.resize(n + 1), outd.resize(n + 1), mp.resize(n + 1);
    while (m--) {
        int u = 0, v = 0;
        cin>>u>>v;
        outd[u]++, ind[v]++;
        mp[u].push_back(v);
    }

    queue<int> Q;
    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            dp[i] = 1;
            Q.push(i);
        }
    }
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for (auto &elem : mp[node]) {
            dp[elem] = (dp[elem] + dp[node]) % 80112002;
            ind[elem]--;
            if (ind[elem] == 0) Q.push(elem);
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (outd[i] == 0) ans += dp[i];
    }

    cout<<ans % 80112002<<endl;
    system("pause");
}