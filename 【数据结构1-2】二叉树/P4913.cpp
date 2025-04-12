//P4913 �����16.��3�����������
//ע��Ҷ�ӽڵ�����У���ע�͵���д��������д��������
//�ƺ��ҵ�д������һ�㣬��������Ϊ����һ��
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
