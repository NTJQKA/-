//P1219 [USACO1.5] 八皇后 Checker Challenge
//优化版
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<vector<int>> ans;
bool scan_col(vector<int> &flag, int row, int col) {//给定要检索的列，如果整列都没有被占用返回true
    for (int i = 0; i < row; ++i) {
        if (flag[i] == col) return false;
    }
    return true;
}
bool scan_diagonal(vector<int> &flag, int row, int col) {//给定坐标，检索对角线，如果对角线没有被占用返回true
    for (int i = 0; i < row; ++i) {
        if (fabs(row - i) == fabs(col - flag[i])) return false;
    }
    return true;
}
void dfs(vector<int> &flag, int times) {
    if (times == n) {
        ans.push_back(flag);
        return;
    }
    else {
        for (int i = 0; i < n; ++i) {//对每一列进行尝试。行就是times，在一个栈内是固定的
            if (scan_col(flag, times, i) && scan_diagonal(flag, times, i)) {
                flag[times] = i;
                dfs(flag, times+1);
                flag[times] = -1;
            }
        }
    }
}
int main() {
    cin>>n;
    //vector<vector<bool>> a(n, vector<bool> (n));//最后记得列数+1，这里没预留第0列
    //二维数组完全没用了，deepseek的这个方法实际上相当于做了一次状压
    vector<int> flag(n, -1);//维护状态数组，意思：(i, flag[i])上放置了皇后。初始特化为-1避免潜在逻辑错误如未被操作时误认为在第0列放置了皇后

    dfs(flag, 0);

    for (int i = 0; i < 3; ++i) {
        for (auto elem : ans[i]) cout<<elem+1<<" ";//从0开始计变成从1开始计
        cout<<endl;
    }
    cout<<ans.size()<<endl;
    system("pause");
}