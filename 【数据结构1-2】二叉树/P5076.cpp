//P5076 �����16.��7����ͨ���������򻯰棩
//case 4����дbreak�ˣ�������30���ӡ���
//��˵setҲ����������vector + lower_bound�ˣ��������insert���пտ��±�׼�ⷨ
#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void solve(int opt, int x) {
    switch (opt) {
        case 1 : cout<<lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1<<endl; break;
        case 2 : cout<<vec[x - 1]<<endl; break;
        case 3 : {
            auto p = lower_bound(vec.begin(), vec.end(), x);
            if (p == vec.begin()) cout<<-INT_MAX<<endl;
            else cout<<*--p<<endl;
            break;
        }
        case 4 : {
            auto p = upper_bound(vec.begin(), vec.end(), x);
            if (p == vec.end()) cout<<INT_MAX<<endl;
            else cout<<*p<<endl;
            break;
        }
        case 5 : {
            auto p = lower_bound(vec.begin(), vec.end(), x);
            vec.insert(p, x);
            break;
        }
    }
}
int main() {
    freopen("P5076_1.in", "r", stdin);
    int q = 0;
    cin>>q;
    while (q--) {
        int opt = 0, x = 0;
        cin>>opt>>x;
        solve(opt, x);
    }
    freopen("CON", "r", stdin);
    system("pause");
}