//P1563 [NOIP 2016 �����] �������
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m;//���С�˸�����ָ������
struct node {
    int flag;
    string job;
};
int loop_plus(int x, int y) {//y�����ɸ�������������������ˣ���������cnt�����ȡ�෴��
    int ret = x + y;
    if (ret >= n) ret -= n;
    else if (ret < 0) ret += n;
    return ret;
}
int main() {
    cin>>n>>m;
    vector<node> a(n);
    for (auto &elem : a) cin>>elem.flag>>elem.job;

    int ptr = 0;
    while (m--) {
        int dir = 0, cnt = 0;//direction, count
        cin>>dir>>cnt;
        if (dir ^ a[ptr].flag == 0) cnt = -cnt;
        ptr = loop_plus(ptr, cnt);
    }
    cout<<a[ptr].job<<endl;
    system("pause");
}