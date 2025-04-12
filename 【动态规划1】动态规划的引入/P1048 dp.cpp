#include <bits/stdc++.h>
using namespace std;
int T, M;
vector<int> a, b, dp;
int main() {
    cin>>T>>M;
    a.resize(M), b.resize(M), dp.resize(T + 1);
    for (int i = 0; i < M; ++i) cin>>a[i]>>b[i];
    for (int i = 0; i < M; ++i) {
        for (int j = T; j >= 1; --j) {
            if (j - a[i] >= 0) dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            else dp[j] = dp[j];//else continue更快，这样写在初学阶段可读性更好
        }
        //for (auto &elem : dp) cout<<elem<<" "; cout<<endl;
    }
    cout<<dp[T]<<endl;
    system("pause");
}