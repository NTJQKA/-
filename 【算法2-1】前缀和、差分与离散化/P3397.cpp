//P3397 地毯
//二维差分。如果掌握了二维前缀和的推法（容斥原理），那么很快就能推出二维差分，实际上，因为互为逆过程，二维前缀和的板子都可以拿来用
#include <bits/stdc++.h>
using namespace std;
int n, m;
void fill_2d_partial_sum(vector<vector<int>> &a, vector<vector<int>> &s) {//n + 1式编号，时间O(mn)，m n为矩阵长宽
    int x = a.size(), y = a[0].size();
    partial_sum(a[1].begin(), a[1].end(), s[1].begin());//第1行边界处理
    for (int i = 1; i < x; ++i) s[i][1] = s[i - 1][1] + a[i][1];//第1列边界处理
    for (int i = 2; i < x; ++i) {
        for (int j = 2; j < y; ++j) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
}
void make_d(vector<vector<int>> &d, pair<int, int> p1, pair<int, int> p2) {
    int &x1 = p1.first, &y1 = p1.second, &x2 = p2.first, &y2 = p2.second;
    d[x1][y1]++;
    int opt = 0;
    if (y2 + 1 <= n) opt++, d[x1][y2 + 1]--;
    if (x2 + 1 <= n) opt++, d[x2 + 1][y1]--;
    if (opt == 2) d[x2 + 1][y2 + 1]++;//其实就是一个&&判断，但是我闲得慌，想这么写
}
int main() {
    cin>>n>>m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    while (m--) {
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        make_d(d, {x1, y1}, {x2, y2});
    }
    fill_2d_partial_sum(d, a);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
}