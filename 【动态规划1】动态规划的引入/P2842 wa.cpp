//P2842 ֽ������ 1
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int main() {
    int n, w;
    cin>>n>>w;
    vector<int> a(n);//, dp(w + 1);
    vector<vector<int>> dp(n, vector<int>(w + 1));
    for (auto &elem : a) cin>>elem;

    for (int i = 0; i <= w; ++i) {
        dp[0][i] = ceil(w / a[0]);
    }//��ʼ��

    /*for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= w; ++j) {
            int k_max = j / a[i];
            int minv = INT_MAX;
            for (int k = 0; k <= k_max; ++k) {
                minv = min(minv, dp[i - 1][j - k * a[i]] + k);
            }
            dp[i][j] = minv;
        }
    }*///��ѧ��01���������Լ�˼·�������ˣ�ʵ���������ֻ��Ҫһ��ά����״̬ת�ƺ�ֱ�ۣ���һ��ֽ�ң�Ȼ��ѯ�ʼ�ȥ����ֽ�Һ�ʣ�������������Сֵ����
    cout<<dp[n - 1][w]<<endl;
    system("pause");
}