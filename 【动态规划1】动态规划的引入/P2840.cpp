//P2840 ֽ������ 2
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;
int n, w;
int main() {
    cin>>n>>w;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    vector<i64> dp(w + 1);
    dp[0] = 1;
    for (int i = 1; i <= w; ++i) {//i��Ҫ�յĽ��
        for (int j = 0; j < n; ++j) {//j�����һ��Ҫ�õ�ֽ��
            if (i - a[j] >= 0) dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }//״̬ת��ʽ���Ǹ�sigma��ת��ΪC���Ժ��ǵ��� +=�����û�������⣬����ɶ��Ի��治��
    }
    cout<<dp[w]<<endl;
    system("pause");
}