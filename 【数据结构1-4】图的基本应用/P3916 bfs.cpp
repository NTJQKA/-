//P3916 Í¼µÄ±éÀú
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> mp;
int main() {
    cin>>n>>m;
    mp.resize(n + 1);
    while (m--) {
        int u = 0, v = 0;
        cin>>u>>v;
        mp[v].push_back(u);
    }
    vector<pair<int, bool>> ans(n + 1);

    queue<int> Q;
    for (int x = n; x >= 1; --x) {
        Q.push(x);
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            if (ans[node].second == false) {
                ans[node].first = x;
                ans[node].second = true;
                for (auto elem : mp[node]) Q.push(elem);
            }
            else continue;
        }
    }

    for (int i = 1; i <= n; ++i) cout<<ans[i].first<<" "; cout<<endl;
    system("pause");
}