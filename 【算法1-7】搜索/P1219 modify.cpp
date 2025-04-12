//P1219 [USACO1.5] �˻ʺ� Checker Challenge
//�Ż���
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<vector<int>> ans;
bool scan_col(vector<int> &flag, int row, int col) {//����Ҫ�������У�������ж�û�б�ռ�÷���true
    for (int i = 0; i < row; ++i) {
        if (flag[i] == col) return false;
    }
    return true;
}
bool scan_diagonal(vector<int> &flag, int row, int col) {//�������꣬�����Խ��ߣ�����Խ���û�б�ռ�÷���true
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
        for (int i = 0; i < n; ++i) {//��ÿһ�н��г��ԡ��о���times����һ��ջ���ǹ̶���
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
    //vector<vector<bool>> a(n, vector<bool> (n));//���ǵ�����+1������ûԤ����0��
    //��ά������ȫû���ˣ�deepseek���������ʵ�����൱������һ��״ѹ
    vector<int> flag(n, -1);//ά��״̬���飬��˼��(i, flag[i])�Ϸ����˻ʺ󡣳�ʼ�ػ�Ϊ-1����Ǳ���߼�������δ������ʱ����Ϊ�ڵ�0�з����˻ʺ�

    dfs(flag, 0);

    for (int i = 0; i < 3; ++i) {
        for (auto elem : ans[i]) cout<<elem+1<<" ";//��0��ʼ�Ʊ�ɴ�1��ʼ��
        cout<<endl;
    }
    cout<<ans.size()<<endl;
    system("pause");
}