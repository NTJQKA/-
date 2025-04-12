//P1135 奇怪的电梯
//当然，这题还有一个方法，yummy不小心说出来的，根据运行时间剪枝。比如如果运行将近1s还正在搜索，大概率是无解了，不如直接kill，然后cout<<-1
//虽然是歪门邪道，但是我猜测如果这么做的话，用差一点的那个面向结果比较的剪枝也能将近100分，可能还是会被hack一两个点
//有空必须学习一下这种方法，虽然没有任何指导意义，但至少有机会提升自己在竞赛中的分数（使用搜索出现意外TLE时），如果MLE就别用了，一般是节点搜重了，死递归，爆栈
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;
int n, from, to;
int his_cnt = INT_MAX;
void dfs(vector<int> &a, vector<int> &b, int pos, int cnt) {
    if (cnt < b[pos]) b[pos] = cnt;
    else return;
    //面向每一步而不是只有一个结果比较的剪枝。
    //for (auto elem : b) cout<<elem<<" "; cout<<endl;
    if (pos == to) {
        his_cnt = cnt;
        return;
    }
    else {
        if (pos + a[pos] >= 0 && pos + a[pos] < n) {
            dfs(a, b, pos + a[pos], cnt+1);
            //cout<<"retreat : "; for (auto elem : b) cout<<elem<<" "; cout<<endl;
        }
        if (pos - a[pos] >= 0 && pos - a[pos] < n) {
            dfs(a, b, pos - a[pos], cnt+1);
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
    vector<int> b(n);//标记到达每一层所需要的最小按键数，理解为里面存的都是history_cnt(min)。yummy出题人的思路
    for (auto &elem : b) elem = INT_MAX;
    dfs(a, b, from, 0);
    his_cnt == INT_MAX ? cout<<-1<<endl : cout<<his_cnt<<endl;
    system("pause");
}