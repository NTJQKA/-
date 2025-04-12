//P1160 队列安排
//使用链表的删除操作和“空迭代器”概念，新学的语法有点多，有空复习下
#include <iostream>
#include <vector>
#include <list>
using namespace std;
using iter = list<int>::iterator;
int n;
int main() {
    cin>>n;
    vector<iter> pos(n+1);//函数值映射到下标（迭代器）
    //vector<bool> flag(n+1);//状态数组，起到替代删除的效果（只是让某个位置 沉默）
    list<int> lis;

    lis.push_back(1);
    pos[1] = lis.begin();//初始化

    int a = 0, b = 0;
    for (int i = 2; i <= n; ++i) {
        cin>>a>>b;
        b? pos[i] = lis.insert(next(pos[a]), i) : pos[i] = lis.insert(pos[a], i);
    }

    int m; cin>>m;
    while (m--) {
        int tmp; cin>>tmp;
        if (pos[tmp] != iter()) {
            lis.erase(pos[tmp]);
            pos[tmp] = iter();
        }
        else continue;
    }
    
    for (auto elem : lis) cout<<elem<<" ";
    system("pause");
}