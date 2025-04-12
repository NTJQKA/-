//P1135 奇怪的电梯
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
int n, from, to;
int his_cnt = INT_MAX;
void dfs(vector<int> &a, vector<bool> &b, int pos, int cnt) {
    b[pos] = true;
    //for (auto elem : b) cout<<elem<<" "; cout<<endl;
    if (pos == to) {
        if (cnt < his_cnt) his_cnt = cnt;
        return;
    }
    else {
        if (pos + a[pos] >= 0 && pos + a[pos] < n && b[pos + a[pos]] == false) {
            dfs(a, b, pos + a[pos], cnt+1);
            b[pos + a[pos]] = false;
            //cout<<"retreat : "; for (auto elem : b) cout<<elem<<" "; cout<<endl;
        }
        if (pos - a[pos] >= 0 && pos - a[pos] < n && b[pos - a[pos]] == false) {
            dfs(a, b, pos - a[pos], cnt+1);
            b[pos - a[pos]] = false;
            //cout<<"retreat : "; for (auto elem : b) cout<<elem<<" "; cout<<endl;
        }
    }
    return;
}
int main() {
    cin>>n>>from>>to;
    from--, to--;//兼容初始化
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    vector<bool> b(n);//标记电梯的每一层是否坐过了
    dfs(a, b, from, 0);
    his_cnt == INT_MAX ? cout<<-1<<endl : cout<<his_cnt<<endl;
    system("pause");
}