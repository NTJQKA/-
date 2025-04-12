//P2440 ľ�ļӹ�
//o(nlogL)
#include <iostream>
#include <vector>
using namespace std;
int n, k;//���Ŀ�����������ö���
bool judge(vector<int> &a, int d) {//���г�Ϊd��С��
    int ans = 0;
    for (auto elem : a) ans += elem / d;
    if (ans >= k) return true;
    else return false;
}
int main() {
    cin>>n>>k;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;

    int l = 0, r = 1e8;
    while (l != r) {
        int mid = l + (r - l + 1) / 2;
        if (judge(a, mid)) l = mid;
        else r = mid - 1;
    }
    cout<<l<<endl;
    system("pause");
}