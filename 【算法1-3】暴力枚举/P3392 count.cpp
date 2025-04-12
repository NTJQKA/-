//P3392 涂条纹
//感觉枚举操作和前缀和操作适合封装一下做成板子。如果每次都现场考虑边界问题，要把人累死的。
//而且代码可读性很差，一旦哪个细节出错了很难debug
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int n, m;
int main() {
    cin>>n>>m;
    vector<string> raw(n);
    for (auto &elem : raw) cin>>elem;
    vector<vector<int>> change_cost(n, vector<int>(3));
    vector<vector<int>> c_c_partial_sum(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        vector<int> appear_times(3);
        for (auto &elem : raw[i]) {
            switch (elem) {
                case 'W':appear_times[0]++;break;
                case 'B':appear_times[1]++;break;
                case 'R':appear_times[2]++;break;
            }
        }//notice that appear_times[0]+[1]+[2] == m
        for (int j = 0; j < 3; ++j) {
            change_cost[i][j] = m - appear_times[j];
            int partial_sum = i == 0 ? 0 : c_c_partial_sum[i-1][j];
            c_c_partial_sum[i][j] = partial_sum + change_cost[i][j];
        }
    }
    int minv = INT_MAX;
    for (int i = 1; i <= n-2; ++i) {
        for (int j = 1; j <= n-1-i; ++j) {
            int sum1 = c_c_partial_sum[i-1][0];
            int sum2 = c_c_partial_sum[i+j-1][1] - c_c_partial_sum[i-1][1];
            int sum3 = c_c_partial_sum[n-1][2] - c_c_partial_sum[i+j-1][2];
            int sum = sum1 + sum2 + sum3;
            minv = min(minv, sum);
        }
    }
    cout<<minv<<endl;
    system("pause");
}
//2 abandoned algorithm
/*for (int j = 0; j < 3; ++j) {
            int sum = 0;
            switch (j) {
                case 0: sum = appear_times[1] + appear_times[2];break;
                case 1: sum = appear_times[0] + appear_times[2];break;
                case 2: sum = appear_times[0] + appear_times[1];break;
            }
            change_cost[i][j] = sum;
        }*/
/*for (int j = 0; j < 3; ++j) {
            int sum = appear_times[(j+1)%3] + appear_times[(j+2)%3];
            change_cost[i][j] = sum;//take turn rules
        }*/