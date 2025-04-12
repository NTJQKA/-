//P1719 最大加权矩形
//二维前缀和？
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int main() {
    cin>>n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> dot;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin>>a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        partial_sum(a[i].begin(), a[i].end(), s[i].begin());
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dot.push_back(make_pair(i, j));
        }
    }
    for (auto &p1 : dot) {//O(n ^ 5)
        int x1 = p1.first, y1 = p1.second;
        for (int i = x1; i <= n; ++i) {
            for (int j = y1; j <= n; ++j) {
                int &x2 = i, &y2 = j;
                int mat_sum = 0;
                for (int k = x1; k <= x2; ++k) {
                    int line_sum = s[k][y2] - s[k][y1 - 1];
                    mat_sum += line_sum;
                }
                ans = max(ans, mat_sum);
            }
        }
    }
    cout<<ans<<endl;
    system("pause");
}