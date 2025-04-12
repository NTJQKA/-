//P2895 [USACO08FEB] Meteor Shower S
//本题的建图方式很有意思，引入了时间T，如果第一想法是把T数值反映在图上而不是建T张图，那么本题思路会变的相当简单
//bfs题里面常有向上下左右走的操作，开一个walk数组存pair表示增量是一个好主意，这样可以避免往走的方向写一堆重复的if
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 320;//农场区域边界，要比本题的x y边界大一些，因为可以跑到流星雨区域外面
const int inf = 1e5;//代替INT_MAX，因我我闲得慌同时不想引入climit
vector<vector<int>> a(maxn, vector<int>(maxn));
vector<pair<int, int>> walk = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int m;
int solve() {
    struct node {
        int x, y, nowtime;
    };
    queue<node> Q;
    vector<vector<bool>> vis(maxn, vector<bool>(maxn));
    Q.push({0, 0, 0});
    vis[0][0] = true;
    while (!Q.empty()) {
        int x = Q.front().x, y = Q.front().y, nowtime = Q.front().nowtime;
        Q.pop();
        if (a[x][y] == inf) return nowtime;
        for (auto &p : walk) {
            int x1 = x + p.first, y1 = y + p.second;
            if (x1 >= 0 && y1 >= 0 && !vis[x1][y1] && nowtime + 1 < a[x1][y1]) {//不用判断是否小于maxn因为边界开的大，一定会在越界之前return
                Q.push({x1, y1, nowtime + 1});
                vis[x1][y1] = true;
            }
        }
        /*if (x - 1 >= 0 && !vis[x - 1][y] && nowtime + 1 < a[x - 1][y]) {
            Q.push({x - 1, y, nowtime + 1});
            vis[x - 1][y] = true;
        }
        if (x + 1 < maxn && !vis[x + 1][y] && nowtime + 1 < a[x + 1][y]) {
            Q.push({x + 1, y, nowtime + 1});
            vis[x + 1][y] = true;
        }
        if (y - 1 >= 0 && !vis[x][y - 1] && nowtime + 1 < a[x][y - 1]) {
            Q.push({x, y - 1, nowtime + 1});
            vis[x][y - 1] = true;
        }
        if (y + 1 >= 0 && !vis[x][y + 1] && nowtime + 1 < a[x][y + 1]) {
            Q.push({x, y + 1, nowtime + 1});
            vis[x][y + 1] = true;
        }*/
    }
    return -1;
}
int main() {
    cin>>m;
    for (auto &row : a) {
        for (auto &elem : row) elem = inf;
    }
    while (m--) {
        int x, y, t; cin>>x>>y>>t;
        a[x][y] = min(a[x][y], t);
        for (auto &p : walk) {
            if (x + p.first >= 0 && y + p.second >= 0) {
                a[x + p.first][y + p.second] = min(a[x + p.first][y + p.second], t);
            }
        }
    }
    cout<<solve()<<endl;
    system("pause");
}