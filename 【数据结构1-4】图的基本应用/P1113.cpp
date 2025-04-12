//P1113тснЯ
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    vector<int> len(n + 1);
    vector<vector<int>> tree(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin>>i;
        cin>>len[i];
        int tmp = 0; 
        cin>>tmp;
        while (1) {
            if (tmp == 0) break;
            tree[i].push_back(tmp);
            cin>>tmp;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int above_sum = 0;
        for (auto elem : tree[i]) above_sum = max(above_sum, len[elem]);
        len[i] = len[i] + above_sum;
    }
    int ans = 0;
    for (auto elem : len) ans = max(ans, elem);
    cout<<ans<<endl;
    system("pause");
}