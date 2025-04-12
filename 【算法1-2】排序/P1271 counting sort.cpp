//P1271 【深基9.例1】选举学生会
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;//n个候选人，共m张选票
    vector<int> a(n+1);
    int tmp = 0;
    while (m--) {
        cin>>tmp;
        a[tmp]++;
    }
    for (int i = 1; i <= n; ++i) {
        while (a[i]) {
            cout<<i<<" ";
            a[i]--;
        }
    }
    system("pause");
}