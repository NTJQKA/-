//P1443 马的遍历
//本题还有一个相当的困难是同时维护图的节点队列和二维答案矩阵。即使思路上知道了用BFS，若不熟练的话在模拟上仍有很大难度
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int m, n;
struct point {//每个点A, A(x, y); 其实用pair就不用定义这个了，但是这样使用到里面的成员的时候可读性更强
    int x, y;
};
queue<point> Q;//节点队列
vector<pair<int, int>> run = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    int x, y;
    cin>>m>>n>>x>>y;
    x--, y--;//兼容预处理
    vector<vector<int>> map(m, vector<int>(n));//answer maps
    for (auto &row : map) {
        for (auto &elem : row) elem = -1;
    }
    point first_point = {x, y};
    Q.push(first_point);
    map[x][y] = 0;

    while (!Q.empty()) {
        point tmp = Q.front();
        Q.pop();
        for (int i = 0; i < 8; ++i) {
            int x_new = tmp.x + run[i].first, y_new = tmp.y + run[i].second;//unchecked
            if (x_new < 0 || x_new >= m || y_new < 0 || y_new >= n || map[x_new][y_new] != -1) continue;
            //很容易忘，但是是算法的核心之一：越界判断防RE和无效操作，确认不是-1保证broad first，因为经数学论证易得很多点是可以被重复走到的，必须记录最快走到的方案
            else {
                map[x_new][y_new] = map[tmp.x][tmp.y] + 1;
                point A = {x_new, y_new};
                Q.push(A);
            }
        }
    }

    for (auto row : map) {
        for (auto elem : row) cout<<elem<<" "; cout<<endl;
    }

    system("pause");
}