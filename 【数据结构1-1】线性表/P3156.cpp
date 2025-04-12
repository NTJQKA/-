//P3156 【深基15.例1】询问学号
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