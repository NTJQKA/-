//P2834 ֽ������ 3
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
    /*for (int i = 0; i <= w; ++i) {
        i % a[0] == 0 ? dp[i] = 1 : dp[i] = 0;
    }*///initialize
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {//��ǰi��ֽ��
        for (int j = 0; j <= w; ++j) {
            //int k_bound = j / a[i];
            /*for (int k = k_bound; k >= 0; --k) {
                dp[j] = 
            }*/
            //dp[j] = k_bound * dp[j - k_bound * a[i]]; k_bound = 0ʱ������
            //�����Ż����Ƶ������Եõ�����ʽ��
            if (j - a[i] >= 0) dp[j] += dp[j - a[i]] % mod;
            //��ά��
            //if (j - a[i] >= 0) dp[i][j] = dp[i - 1][j] + dp[i][j - a[i]];
            //else dp[i][j] = dp[i - 1][j];
            //i��0��nö�٣�j��0��wö�٣�����ѹά��ʡȥelse
        }
    }
    dp[w] %= mod;//ʣ��ϵ����֪ʶ���������д����+=ȡģ��ʽ���������Ҫ��һ��%=��
    cout<<dp[w]<<endl;
    system("pause");
}