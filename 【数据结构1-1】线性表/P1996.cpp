//P1996 约瑟夫问题
#include <iostream>
#include <queue>
using namespace std;
int n, m;
queue<int> q;
int main() {
    cin>>n>>m;
    for (int i = 1; i <= n; ++i) q.push(i);
    while (!q.empty()) {
        for (int cnt = 1; cnt < m; cnt++) {
            q.push(q.front());
            q.pop();//先用后扔的逻辑，连tmp都省了
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    system("pause");
}