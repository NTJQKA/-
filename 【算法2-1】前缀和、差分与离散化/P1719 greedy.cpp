//P1719 最大加权矩形
//突然感觉不行，因为矩形必须是连续的，这题并不是求重排后矩阵的最大子矩阵和……那这个残次品程序就当是练习stl二维vector排序了
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
struct veccmp {
    int column;
    veccmp(int col) : column(col) {}//原理暂未知，但是好像构造函数的名字和结构体名字要取的一样
    bool operator()(const vector<int>& row1, const vector<int>& row2) {
        return row1[column] < row2[column];
    }
};
void sortMatrixByColumn(vector<vector<int>>& matrix, int i) {
    sort(matrix.begin(), matrix.end(), veccmp(i));
}
vector<vector<int>> a(n + 1, vector<int>(n + 1));
void vec_sort(vector<vector<int>> &a) {
    for (int i = 1; i <= n; ++i) sort(a[i].begin() + 1, a[i].end(), greater<int>());
    sort(a.begin() + 1, a.end(), greater<vector<int>>());
}
int main() {
    cin>>n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) cin>>a[i][j];
    }
    
    vec_sort(a);
    //sortMatrixByColumn(a, 4);

    for (auto &row : a) {
        for (auto &elem : row) cout<<elem<<" "; cout<<endl;
    }
    system("pause");
}