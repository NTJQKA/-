//P1219 [USACO1.5] 八皇后 Checker Challenge
//效率最低的一版。除了让deepseek帮忙找到了scan_diagonal中潜在的下标越界错误以外没有进行任何优化
//一开始想法是把一个格子变成true之后对其所在行列和对角线格子全部进行染色，类似于BFS涂色那道题，但是这样成本依然很高，而且我怕影响真正皇后所在格子
//看了deepseek的推荐，做出两个数组，维护皇后所在位置的坐标，然后比对纵坐标或者完全坐标来判断是否违规，可以大大加快速度，只是代码可读性会略微变差
//此外还涉及了二维vector的一些规定操作语法，有空复习一下
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
//vector<int> irow(n);
vector<vector<int>> ans;//(n, irow);//存答案的
bool scan_col(vector<vector<bool>> &a, int col) {//给定要检索的列，如果整列都没有被占用返回true
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (a[i][col]) {
            flag = false;
            break;
        }
    }
    return flag;
}
bool scan_diagonal(vector<vector<bool>> &a, int row, int col) {//给定坐标，检索对角线，如果对角线没有被占用返回true
    bool flag = true;
    for (int i = 0; i < row; ++i) {
        int d = fabs(row - i);
        if (col-d >= 0 && a[i][col-d] || a[i][col+d] && col+d < n) {
            flag = false;
            break;
        }
    }
    /*for (int i = row+1; i < n; ++i) {
        int d = fabs(row - i);
        if (a[i][col-d] || a[i][col+d]) {
            flag = false;
            break;
        }
    }*///没用，因为搜索是从上往下搜的，下面的格子都是空的
    return flag;
}
void dfs(vector<vector<bool>> &a, int times) {
    if (times == n) {
        vector<int> tmp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) tmp[i] = j;
            }
        }
        ans.push_back(tmp);
        return;
    }
    else {
        for (int i = 0; i < n; ++i) {//对每一列进行尝试。行就是times，在一个栈内是固定的
            if (scan_col(a, i) && scan_diagonal(a, times, i)) {
                a[times][i] = true;
                dfs(a, times+1);
                a[times][i] = false;
            }
        }
    }
}
int main() {
    cin>>n;
    vector<bool> row(n);
    vector<vector<bool>> a(n, row);//最后记得列数+1，这里没预留第0列

    dfs(a, 0);

    for (int i = 0; i < 3; ++i) {
        for (auto elem : ans[i]) cout<<elem+1<<" ";//从0开始计变成从1开始计
        cout<<endl;
        /*for (int j = 0; j < n; ++j) {
            cout<<ans[i][j]
        }*/
    }
    cout<<ans.size()<<endl;
    system("pause");
}