//P1219 [USACO1.5] �˻ʺ� Checker Challenge
//Ч����͵�һ�档������deepseek��æ�ҵ���scan_diagonal��Ǳ�ڵ��±�Խ���������û�н����κ��Ż�
//һ��ʼ�뷨�ǰ�һ�����ӱ��true֮������������кͶԽ��߸���ȫ������Ⱦɫ��������BFSͿɫ�ǵ��⣬���������ɱ���Ȼ�ܸߣ���������Ӱ�������ʺ����ڸ���
//����deepseek���Ƽ��������������飬ά���ʺ�����λ�õ����꣬Ȼ��ȶ������������ȫ�������ж��Ƿ�Υ�棬���Դ��ӿ��ٶȣ�ֻ�Ǵ���ɶ��Ի���΢���
//���⻹�漰�˶�άvector��һЩ�涨�����﷨���пո�ϰһ��
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
//vector<int> irow(n);
vector<vector<int>> ans;//(n, irow);//��𰸵�
bool scan_col(vector<vector<bool>> &a, int col) {//����Ҫ�������У�������ж�û�б�ռ�÷���true
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (a[i][col]) {
            flag = false;
            break;
        }
    }
    return flag;
}
bool scan_diagonal(vector<vector<bool>> &a, int row, int col) {//�������꣬�����Խ��ߣ�����Խ���û�б�ռ�÷���true
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
    }*///û�ã���Ϊ�����Ǵ��������ѵģ�����ĸ��Ӷ��ǿյ�
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
        for (int i = 0; i < n; ++i) {//��ÿһ�н��г��ԡ��о���times����һ��ջ���ǹ̶���
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
    vector<vector<bool>> a(n, row);//���ǵ�����+1������ûԤ����0��

    dfs(a, 0);

    for (int i = 0; i < 3; ++i) {
        for (auto elem : ans[i]) cout<<elem+1<<" ";//��0��ʼ�Ʊ�ɴ�1��ʼ��
        cout<<endl;
        /*for (int j = 0; j < n; ++j) {
            cout<<ans[i][j]
        }*/
    }
    cout<<ans.size()<<endl;
    system("pause");
}