//P1563 [NOIP 2016 提高组] 玩具谜题
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, m;//玩具小人个数，指令条数
struct node {
    int flag;
    string job;
};
int loop_plus(int x, int y) {//y可正可负，不交给这个函数管了，主函数里cnt看情况取相反数
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