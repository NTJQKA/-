//P2404 ��Ȼ���Ĳ������
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
void dfs(int x, int need) {
    if (need == 0) {
        if (a.size() == 1) return;
        for (int i = 0; i + 1 < a.size(); ++i) cout<<a[i]<<"+";
        cout<<a.back()<<endl;
        return;
    }
    for (int i = x; i <= need; ++i) {//ע����<=����< ����û�д�
        a.push_back(i);
        dfs(i, need - i);
        a.pop_back();
    }
}
int main() {
    int n; cin>>n;
    dfs(1, n);
    system("pause");
}