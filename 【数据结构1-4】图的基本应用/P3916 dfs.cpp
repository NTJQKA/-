//P3916 图的遍历
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> mp;
void dfs(vector<pair<int, bool>> &ans, int node, int x) {
    if (ans[node].second == false) {//给根节点涂色
        ans[node].first = x;
        ans[node].second = true;
        /*if (mp[node].size() == 0) {//最子子节点了
            return;
        }*/
        //想一下，并不需要，因为如果有if的这个条件就不会进下面的for循环，就会出外面if，默认return了
        for (int i = 0; i < mp[node].size(); ++i) {
            dfs(ans, mp[node][i], x);
        }
    }
    else return;
    //else时什么都不做，一是为了避免出现图中闭环，无限递归，二是本题倒序搜索的最优性质
    //不过主要还是第一点，因为x不依靠递归过程改变，而是在主函数里for循环枚举得到，也就是说x = x0时的dfs，图中每个能联通的节点都会被赋值为x，都是优的
}
int main() {
    cin>>n>>m;
    mp.resize(n + 1);
    while (m--) {
        int u = 0, v = 0;
        cin>>u>>v;
        mp[v].push_back(u);
    }
    vector<pair<int, bool>> ans(n + 1);
    
    //for (int i = 1; i <= n; ++i) ans[i].first = i;

    for (int i = n; i >= 1; --i) {
        dfs(ans, i, i);
    }

    for (int i = 1; i <= n; ++i) cout<<ans[i].first<<" "; cout<<endl;
    system("pause");
}