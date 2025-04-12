//P4715 ¡¾Éî»ù16.Àı1¡¿ÌÔÌ­Èü
#include <iostream>
#include <vector>
using namespace std;
struct bundle {
    int value;
    int index;
};
int n;
int main() {
    cin>>n;
    int total = 1 << n;
    vector<vector<bundle>> a(n+1, vector<bundle>());
    for (int i = 0; i < total; ++i) {
        int tmp;
        cin>>tmp;
        a[0].push_back({tmp, i+1});
    }

    total >>= 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < total; ++j) {
            if (a[i-1][2*j].value > a[i-1][2*j+1].value) a[i].push_back(a[i-1][2*j]);
            else a[i].push_back(a[i-1][2*j+1]);
        }
        total >>= 1;
        //for (auto elem : a[i]) cout<<elem.value<<" "; cout<<endl;
    }
    
    int min_index = a[n-1][0].value < a[n-1][1].value ? a[n-1][0].index : a[n-1][1].index;
    cout<<min_index<<endl;
    system("pause");
}