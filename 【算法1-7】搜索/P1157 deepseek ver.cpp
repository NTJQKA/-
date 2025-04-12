#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    // ʹ��ջ����״̬����ǰ·������һ����ʼλ��
    stack<pair<vector<int>, int>> stk;
    stk.push({vector<int>(), 1});

    while (!stk.empty()) {
        auto [path, start] = stk.top();
        stk.pop();

        if (path.size() == r) { // ��������ʱ���
            for (int num : path)
                cout << setw(3) << num;
            cout << endl;
            continue;
        }

        // ʣ��Ԫ�ز����Թ������ʱ��֦
        int needed = r - path.size();
        if (n - start + 1 < needed) continue;

        // ����ѹջ�Ա�֤����˳����ȷ����С����
        for (int i = n; i >= start; --i) {
            vector<int> new_path(path);
            new_path.push_back(i);
            stk.push({new_path, i + 1});
            //������ʱvector��ans+i�ȼ���ans+i��ѹ���-i��ǰ�߷���ֱ�ۣ����߿���ʱ�俪��СһЩ
        }
    }
    system("pause");
    return 0;
}