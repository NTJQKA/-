//P3392 Ϳ����
//����ȷdfs/dp/��ѧ�Ƶ� ���Եõ�depthΪ50��ʱ�����ֻ��1176�ֿ��ܣ����������У�
//���ⲻ֪����������Ĳ��ã�����ɶ�������ޱȣ������ϵ�ʷ��ʱ���������ע����̫��ɢ��
//����ö�ٰ� �� �죨��ʵ����ö�ٰ� �� ��죬ֻ��Ҫn?���ĸ���������Ȼ��ǰ׺����changecost����
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
int depth, m;
vector<char> ch = {'W', 'B', 'R'};
//vector<int> ans;
vector<vector<int>> change_cost;
int minv = INT_MAX;

//vector<bool> vis(3);
void dfs(int cnt, int i, int sum) {
    //cout<<"now, dfs("<<cnt<<", "<<i<<")"<<endl;
    //vis[i] = true;
    if (cnt == depth - 2) {
        if (i == 0) {
            sum += change_cost[cnt+1][i+1] + change_cost[cnt+2][i+2];
        }
        else if (i == 1) {
            change_cost[cnt+1][i] < change_cost[cnt+1][i+1] ? sum += change_cost[cnt+1][i] : sum += change_cost[cnt+1][i+1];
            sum += change_cost[cnt+2][i+1];
        }
        else {
            sum += change_cost[cnt+1][i] + change_cost[cnt+2][i];
        }
        minv = min(minv, sum);
        return;
    }

    else {
        if (i == 0 || i == 1) {
            dfs(cnt+1, i, sum + change_cost[cnt+1][i]);
            dfs(cnt+1, i+1, sum + change_cost[cnt+1][i+1]);
        }
        else dfs(cnt+1, i, sum + change_cost[cnt+1][i]);
    }
}

int main() {
    cin>>depth>>m;
    change_cost.resize(depth + 1);
    for (auto &elem : change_cost) elem.resize(3);//����depth*3��

    vector<string> raw(depth + 1);
    for (int i = 1; i <= depth; ++i) cin>>raw[i];

    /*    string str_w(m, 'W');
    string str_b(m, 'B');
    string str_r(m, 'R');*/
    for (int i = 1; i <= depth; ++i) {
        for (int j = 0; j <= 2; ++j) {
            int sum = 0;
            for (auto elem : raw[i]) {
                if (elem != ch[j]) sum++;
            }
            change_cost[i][j] = sum;
        }
    }   
    dfs(1, 0, change_cost[1][0]);
    cout<<minv<<endl;
    system("pause");
}