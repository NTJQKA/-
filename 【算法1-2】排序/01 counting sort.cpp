#include <iostream>
#include <vector>
using namespace std;
int times[10000005];
//计数排序使用计数数组。一般内存限制下int数组最好不要开一千万以上，即1e7
//也就是说，如果每一个元素，处于1e7以下且其他地方不太需要开长数组和矩阵，可以考虑下用计数排序替代快排；1e7以上禁止计数排序
void counting_sort(vector<int> &a) {
    for (auto elem : a) times[elem]++;
    int ptr = 0;//这里默认每个元素范围是0到某一个正整数了，实际上从题目标注的元素范围左界出发会再快一点点
    for (auto &elem : a) {
        while (times[ptr] == 0) ptr++;
        elem = ptr;
        times[ptr]--;
    }
}
int main() {
    int n; cin>>n;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    counting_sort(a);
    for (auto elem : a) cout<<elem<<" "; cout<<endl;
    system("pause");
}