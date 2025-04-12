//P2404 自然数的拆分问题
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
void dfs(int x, int need) {
    if (need == 0) {
        if (a.size() == 1) return;
        for (int i = 0; i + 1 < a.size(); ++i) cout<<a[i]<<"+";
        cout<<a.back()<<endl;
        return;
    }
    for (int i = x; i <= need; ++i) {//注意是<=不是< 否则没有答案
        a.push_back(i);
        dfs(i, need - i);
        a.pop_back();
    }
}
int main() {
    int n; cin>>n;
    dfs(1, n);
    system("pause");
}