//P3156 �����15.��1��ѯ��ѧ��
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;
    vector<int> a(n);
    for (auto &elem : a) cin>>elem;
    while (m--) {
        int ptr;
        cin>>ptr;
        cout<<a[ptr-1]<<endl;
    }
    system("pause");
}