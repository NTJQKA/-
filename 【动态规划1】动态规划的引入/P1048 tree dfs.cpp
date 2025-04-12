//我写的这种dfs跟OIwiki上的不一样。这样写不仅容易写错（要在草纸上把树画清楚，找好栈之间的控制进入关系，分析dfs和边界判断放在for内还是外（虽然根据经验，一般都是dfs和边界判断放for里面）），还没法用记搜优化
//对本题而言，记搜就是01背包dp的递归写法，不是建树那种DFS，要是硬和DFS对应，应该是对于每个pos，只有0和1（草药取或不取）两种状态的DFS，其实等同于M层for循环枚举，只不过由于记忆化数组记录过程量，保证每个pos只访问1次而已
#include <bits/stdc++.h>
#define v_print(x) for (auto &elem : x) cout<<elem<<" "; cout<<endl;
using namespace std;
int T, M;
int ans;
vector<int> a, b;//a : time, b : value
vector<bool> used;
void dfs(int pos, int t, int v, int &t_op) {
    if (clock() - t_op > 9900) {//卡时 但是不知道怎么回事出错了，填990的时候，程序只有8ms就被判WA了
        cout<<ans<<endl;
        exit(0);
    }
    for (int i = pos; i < M; ++i) {//let i goes from pos, to avoid same situation
        if (t + a[i] > T) {
            ans = max(ans, v);
            continue;
        }
        //else (t + a[i] <= T)
        if (i == M - 1) ans = max(ans, v + b[i]);//t + a[pos] <= T and pos = M - 1
        dfs(i + 1, t + a[i], v + b[i], t_op);
    }
}
int main() {
    int t_op = clock();
    cin>>T>>M;
    a.resize(M), b.resize(M), used.resize(M);
    for (int i = 0; i < M; ++i) cin>>a[i]>>b[i];
    //v_print(a) v_print(b)
    dfs(0, 0, 0, t_op);
    //if (!ans) ans = accumulate(b.begin(), b.end(), 0);//hack when dfs does not reach if (t >= T)
    cout<<ans<<endl;
    system("pause");
}