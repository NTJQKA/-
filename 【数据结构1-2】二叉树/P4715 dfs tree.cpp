//@kkksc03
//这个方法需要熟知二叉树的一些性质和递归，不太好想，但是如果会写的话比递推的方法更板，不容易出错
#include <iostream>
using namespace std;
int value[260], winner[260];//最多2^8-1 = 255个节点
int n;
int team_amount;//const
int leaf_node_start;//const
void dfs(int x) {
    if (x >= leaf_node_start) return;
    else {
        dfs(2 * x);
        dfs(2 * x + 1);
        if (value[2*x] > value[2*x+1]) {
            value[x] = value[2*x];
            winner[x] = winner[2*x];
        }
        else {
            value[x] = value[2*x+1];
            winner[x] = winner[2*x+1];
        }
    }
}
int main() {
    cin>>n;
    team_amount = 1 << n;
    leaf_node_start = team_amount;//数学可证
    for (int i = 0; i < team_amount; ++i) {
        cin>>value[i + (leaf_node_start)];
        winner[i + (leaf_node_start)] = i + 1;
    }
    dfs(1);
    int ans = value[2] < value[3] ? winner[2] : winner[3];
    cout<< ans <<endl;
    system("pause");
}
