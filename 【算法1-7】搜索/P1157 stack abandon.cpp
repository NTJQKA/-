//P1157 ��ϵ����
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>
using namespace std;
int n, r;
stack<int> S;//��ʵ���Բ����κβ�����������һ��int�����жϼ�֦����
vector<int> ans;
bool flag;//false
int main() {
    cin>>n>>r;
    vector<bool> a(n+1);//��¼ÿ��Ԫ����û�ù�
    S.push(1); a[1] = true;//��ʼ��
    while (!S.empty() && flag == false) {//��ʵS�ǿտ���ȥ��
        if (ans.size() == r) {
            for (auto elem : ans) cout<<setw(3)<<elem;
            cout<<endl;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i]) continue;
            else {
                if (!ans.empty() && i < ans.back()) continue;
                else {
                    ans.push_back(i);
                    a[i] = true;
                    S.push(i);

                }
            }
        }
    }
}