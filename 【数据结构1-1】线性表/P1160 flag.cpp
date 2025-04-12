//P1160 ���а���
#include <iostream>
#include <vector>
#include <list>
using namespace std;
using iter = list<int>::iterator;
int n;
int main() {
    cin>>n;
    vector<iter> pos(n+1);//����ֵӳ�䵽�±꣨��������
    vector<bool> flag(n+1);//״̬���飬�����ɾ����Ч����ֻ����ĳ��λ�� ��Ĭ��
    list<int> lis;

    lis.push_back(1);
    pos[1] = lis.begin();//��ʼ��

    int a = 0, b = 0;
    for (int i = 2; i <= n; ++i) {
        cin>>a>>b;
        b? pos[i] = lis.insert(next(pos[a]), i) : pos[i] = lis.insert(pos[a], i);
    }

    int m; cin>>m;
    while (m--) {
        int tmp; cin>>tmp;
        flag[tmp] = true;
    }
    
    for (auto elem : lis) {
        if (flag[elem]) continue;
        else cout<<elem<<" ";
    }
    system("pause");
}