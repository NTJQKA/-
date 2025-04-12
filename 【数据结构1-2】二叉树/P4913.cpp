//P4913 【深基16.例3】二叉树深度
//注意叶子节点的特判，被注释掉的写法和现有写法都可以
//似乎我的写法还快一点，可能是因为树少一层
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int left;
    int right;
};
int dfs(vector<node> &a, int x) {
    //if (a[x].left == 0 && a[x].right == 0) return 1;
    if (x == 0) return 0;
    else {
        return max(dfs(a, a[x].left), dfs(a, a[x].right)) + 1;
    }
}
int main() {
    int n; cin>>n;
    vector<node> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i].left>>a[i].right;
    }

    cout<<dfs(a, 1)<<endl;
    system("pause");
}
