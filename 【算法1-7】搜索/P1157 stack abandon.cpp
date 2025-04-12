//P1157 组合的输出
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
int n, r;
stack<int> S;//其实可以不填任何参数，这里填一个int用来判断剪枝好了
vector<int> ans;
bool flag;//false
int main() {
    cin>>n>>r;
    vector<bool> a(n+1);//记录每个元素用没用过
    S.push(1); a[1] = true;//初始化
    while (!S.empty() && flag == false) {//其实S非空可以去了
        if (ans.size() == r) {
            for (auto elem : ans) cout<<setw(3)<<elem;
            cout<<endl;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i]) continue;
            else {
                if (!ans.empty() && i < ans.back()) continue;
                else {
                    ans.push_back(i);
                    a[i] = true;
                    S.push(i);

                }
            }
        }
    }
}