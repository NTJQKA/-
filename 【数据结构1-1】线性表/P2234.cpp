//P2234 [HNOI2002] 营业额统计
#include <bits/stdc++.h>
using namespace std;
int n, ans;
set<int> SET;
int main() {
    cin>>n;
    int num = 0; cin>>num;
    SET.insert(num);
    ans += num;
    n--;
    while (n--) {
        num = 0; cin>>num;
        auto i = SET.lower_bound(num);
        if (i == SET.begin()) {
            ans += fabs((*i) - num);
        }
        else if (i == SET.end()) {
            i--;
            ans += fabs((*i) - num);
        }
        else {
            int v1 = fabs((*i) - num);
            i--;
            int v2 = fabs((*i) - num);
            ans += min(v1, v2);
        }

        SET.insert(num);
    }
    cout<<ans<<endl;
    system("pause");
}