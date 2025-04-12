//P1135 奇怪的电梯
//初始节点vis应该打成true，因为从a点到a点可以一次键都不按，这一点题意理解疏忽了
#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
    cin>>n>>a>>b;
    a--, b--;
    vector<int> floor(n);
    vector<bool> vis(n);
    vector<int> step(n);
    for (auto &elem : floor) cin>>elem;
    queue<pair<int, int>> Q;//floor and step_now
    vis[a] = true, step[a] = 0;
    Q.push({a, 0});
    while (!Q.empty()) {
        pair<int, int> node = Q.front();
        Q.pop();
        if (node.first - floor[node.first] >= 0 && !vis[node.first - floor[node.first]]) {
            vis[node.first - floor[node.first]] = true;
            step[node.first - floor[node.first]] = node.second + 1;
            Q.push({node.first - floor[node.first], node.second + 1});
        }
        if (node.first + floor[node.first] < n && !vis[node.first + floor[node.first]]) {
            vis[node.first + floor[node.first]] = true;
            step[node.first + floor[node.first]] = node.second + 1;
            Q.push({node.first + floor[node.first], node.second + 1});
        }
    }
    if (!vis[b]) cout<<-1<<endl;
    else cout<<step[b]<<endl;
    system("pause");
}