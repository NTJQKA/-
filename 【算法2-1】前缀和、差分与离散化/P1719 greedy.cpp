//P1719 ����Ȩ����
//ͻȻ�о����У���Ϊ���α����������ģ����Ⲣ���������ź���������Ӿ���͡���������д�Ʒ����͵�����ϰstl��άvector������
#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
struct veccmp {
    int column;
    veccmp(int col) : column(col) {}//ԭ����δ֪�����Ǻ����캯�������ֺͽṹ������Ҫȡ��һ��
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