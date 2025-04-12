//P3397 ��̺
//��ά��֡���������˶�άǰ׺�͵��Ʒ����ݳ�ԭ������ô�ܿ�����Ƴ���ά��֣�ʵ���ϣ���Ϊ��Ϊ����̣���άǰ׺�͵İ��Ӷ�����������
#include <bits/stdc++.h>
using namespace std;
int n, m;
void fill_2d_partial_sum(vector<vector<int>> &a, vector<vector<int>> &s) {//n + 1ʽ��ţ�ʱ��O(mn)��m nΪ���󳤿�
    int x = a.size(), y = a[0].size();
    partial_sum(a[1].begin(), a[1].end(), s[1].begin());//��1�б߽紦��
    for (int i = 1; i < x; ++i) s[i][1] = s[i - 1][1] + a[i][1];//��1�б߽紦��
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
    if (opt == 2) d[x2 + 1][y2 + 1]++;//��ʵ����һ��&&�жϣ��������еûţ�����ôд
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