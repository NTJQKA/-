//P2842 ֽ������ 1
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int main() {
    int n, w;
    cin>>n>>w;
    vector<int> a(n), dp(w + 1);
    for (auto &elem : a) cin>>elem;
    for (auto &elem : dp) elem = /*INT_MAX*/1e9;
    //������һ���ܿӵĵ㣺INT_MAX������⣬��Ϊ���������ʹ����dp[] + 1���п��ܵ��³���-1����-1�ǻ�һֱռ��minv��λ�õ�
    dp[0] = 0;
    for (int i = 1; i <= w; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] >= 0) dp[i] = min(dp[i], dp[i - a[j]] + 1);
        }
    }
    cout<<dp[w]<<endl;
    system("pause");
}