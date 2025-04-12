//P1443 ��ı���
//���⻹��һ���൱��������ͬʱά��ͼ�Ľڵ���кͶ�ά�𰸾��󡣼�ʹ˼·��֪������BFS�����������Ļ���ģ�������кܴ��Ѷ�
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int m, n;
struct point {//ÿ����A, A(x, y); ��ʵ��pair�Ͳ��ö�������ˣ���������ʹ�õ�����ĳ�Ա��ʱ��ɶ��Ը�ǿ
    int x, y;
};
queue<point> Q;//�ڵ����
vector<pair<int, int>> run = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
    int x, y;
    cin>>m>>n>>x>>y;
    x--, y--;//����Ԥ����
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
            //�����������������㷨�ĺ���֮һ��Խ���жϷ�RE����Ч������ȷ�ϲ���-1��֤broad first����Ϊ����ѧ��֤�׵úܶ���ǿ��Ա��ظ��ߵ��ģ������¼����ߵ��ķ���
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