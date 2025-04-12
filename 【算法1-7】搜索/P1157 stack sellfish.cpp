//P1157 组合的输出
//与递归DFS不同之处：每进一次while循环，只pop掉一个栈，但是取出的这个top进行一些操作之后可能压入一堆栈，也就是树上更深的节点
//所以用stack显式模拟时应当按树的层数顺序压栈，而不是按枝条顺序压栈。因为LIFO特性，有时还得倒序压栈，例如本题
//用stack模拟DFS的话，“回溯”这一操作很困难，所以基本上是选择保存当前节点的所有信息的。递归方法中，回溯/保存节点信息二选一即可
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
int n, r;
stack<vector<int>> S;
int main() {
    cin>>n>>r;
    vector<int> l(n+1);
    for (int i = 0; i <= n; ++i) {
        l[i] = n - i;
    }
    //这个数组的意义是表示ans最后选择到i时，往后还有几种选择方式，如果r - ans.size() > l[i]，直接剪枝
    //写错了，应该是r-ans.size()-1，因为为了节省常数时间，这个时候对象还是i，还没有把他push到ans里面
    S.push(vector<int>());
    while (!S.empty()) {
        vector<int> ans = S.top();
        S.pop();
        if (ans.size() == r) {
            for (auto elem : ans) cout<<setw(3)<<elem;
            cout<<endl;
            continue;
        }
        //bool judge;
        for (int i = n, back = ans.empty()? 0 : ans.back(); i > back; --i) {
            //cout<<ans.size()<<endl;
            //cout<<"i的值为 "<<i<<", ";
            //cout<<"有强转"<<r - (int)(ans.size()) - 1<<" "<<l[i]<<endl;
            //cout<<r - ans.size() - 1<<" "<<l[i]<<endl;            
            //system("pause");
            if (r - ans.size() - 1 > l[i]) continue;//不用强转，因为左边保证非负
            else {
                //cout<<"cheer"<<endl;
                ans.push_back(i);
                S.push(ans);
                ans.pop_back();
            }
        }
    }
    system("pause");
}