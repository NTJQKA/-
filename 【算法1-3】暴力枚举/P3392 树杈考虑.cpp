//P3392 Í¿ÌõÎÆ
//1176
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
const int depth = 50;
long long sol;
vector<char> ch = {'W', 'B', 'R'};
vector<int> ans;
//vector<bool> vis(3);
void dfs(int cnt, int i) {
    cout<<"now, dfs("<<cnt<<", "<<i<<")"<<endl;
    //vis[i] = true;
    if (cnt == depth - 2) {
        if (i == 0 || i == 2) {
            sol++;
            return;
        }
        else {
            sol += 2;
            return;
        }
    }

    else {
        if (i < 2) {
            dfs(cnt+1, i);
            dfs(cnt+1, i+1);
        }
        else dfs(cnt+1, i);
    }
}

int main() {
    //cout<<pow(3, 48)<<endl;
    int sum = 0;
    for (int i = 1; i <= 48; ++i) {
        sum += i;
    } cout<<sum<<endl;
    dfs(1, 0);
    cout<<sol<<endl;
    system("pause");
}