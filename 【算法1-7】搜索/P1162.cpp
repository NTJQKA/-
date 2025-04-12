//P1162 ��Ϳ��ɫ
//ע��bfs���е�һ��trick������Ϳɫʱ����ʱ��Ҫ��Ե��һȦ(n + 2)��Ŀ����Ϊ�˱�֤��Ե����(0, 0)������Ϳ�����ͨ��������������ϱ��ĸ������о��״��Ե��ͿɫͿ������
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n;
vector<vector<int>> a;
vector<pair<int, int>> walk = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void solve() {
    queue<pair<int, int>> Q;
    vector<vector<bool>> vis(n + 2, vector<bool>(n + 2));
    Q.push({0, 0});
    a[0][0] = 2;
    vis[0][0] = true;
    while (!Q.empty()) {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();
        for (auto &p : walk) {
            int x1 = x + p.first, y1 = y + p.second;
            if (x1 >= 0 && x1 <= n + 1 && y1 >= 0 && y1 <= n + 1 && !vis[x1][y1] && a[x1][y1] == 0) {
                Q.push({x1, y1});
                a[x1][y1] = 2;
                vis[x1][y1] = true;
            }
        }
    }
    for (auto &row : a) {
        for (auto &elem : row) {
            if (elem == 2) elem = 0;
            else if (elem == 0) elem = 2;
        }
    }
}
int main() {
    cin>>n;
    a.resize(n + 2);
    for (auto &elem : a) elem.resize(n + 2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin>>a[i][j];
    }
    solve();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cout<<a[i][j]<<" "; cout<<endl;
    }
    system("pause");
}