//P1719 最大加权矩形
//二维前缀和
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
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
int getsum(vector<vector<int>> &s, pair<int, int> &a, pair<int, int> &b) {//n + 1式编号，时间O(1)
    int &x1 = a.first, &y1 = a.second, &x2 = b.first, &y2 = b.second;
    return s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2];
}
int main() {
    cin>>n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin>>a[i][j];
    }
    fill_2d_partial_sum(a, s);
    for (int x1 = 1; x1 <= n; ++x1) {
        for (int y1 = 1; y1 <= n; ++y1) {
            for (int x2 = x1; x2 <= n; ++x2) {
                for (int y2 = y1; y2 <= n; ++y2) {
                    auto p1 = make_pair(x1, y1), p2 = make_pair(x2, y2);
                    ans = max(ans, getsum(s, p1, p2));
                }
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
}