//P1271 【深基9.例1】选举学生会
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;//n个候选人，共m张选票
    vector<int> a(m);
    for (auto &elem : a) cin>>elem;
    sort(a.begin(), a.end());
    for (auto elem : a) cout<<elem<<" ";
    system("pause");
}