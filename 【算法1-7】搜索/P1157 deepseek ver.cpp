#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    // 使用栈保存状态：当前路径和下一个起始位置
    stack<pair<vector<int>, int>> stk;
    stk.push({vector<int>(), 1});

    while (!stk.empty()) {
        auto [path, start] = stk.top();
        stk.pop();

        if (path.size() == r) { // 满足条件时输出
            for (int num : path)
                cout << setw(3) << num;
            cout << endl;
            continue;
        }

        // 剩余元素不足以构成组合时剪枝
        int needed = r - path.size();
        if (n - start + 1 < needed) continue;

        // 逆序压栈以保证处理顺序正确（从小到大）
        for (int i = n; i >= start; --i) {
            vector<int> new_path(path);
            new_path.push_back(i);
            stk.push({new_path, i + 1});
            //创建临时vector存ans+i等价于ans+i，压入后-i，前者符合直观，后者可能时间开销小一些
        }
    }
    system("pause");
    return 0;
}