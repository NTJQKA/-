//P1996 Լɪ������
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
            q.pop();//���ú��ӵ��߼�����tmp��ʡ��
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    system("pause");
}