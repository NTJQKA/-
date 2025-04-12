//P1241 括号序列
//这个题并不需要插入insert，因为没有后续操作要求，直接打印输出的，所以存字符串时候用什么数据结构都可以
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    vector<pair<char, bool>> str;
    stack<int> match;
    /*char ch;
    while ((ch = getchar()) != '\n') str.push_back({ch, false});*/
    //这读入有点说法，getchar还是没完全搞明白，不知道oj上读入的结尾是不是'\n'，我在本地freopen跑的时候用\n判断终止可行
    //while (ch = getchar())在我的本地跑，得不到任何结果
    string tmp;
    cin>>tmp;
    for (auto &elem : tmp) str.push_back({elem, false}); 
    //只有用字符串读入，洛谷上这个题才能过……无语了

    for (int i = 0; i < str.size(); ++i) {
        auto &elem = str[i];
        if (elem.first == '(' || elem.first == '[') match.push(i);
        else if (elem.first == ')') {
            if (match.empty()) continue;
            else {
                int near_left = match.top();
                if (str[near_left].first == '(') {
                    str[near_left].second = true;
                    elem.second  =true;
                    match.pop();
                }
            }
        }
        else {
            if (match.empty()) continue;
            else {
                int near_left = match.top();
                if (str[near_left].first == '[') {
                    str[near_left].second = true;
                    elem.second  =true;
                    match.pop();
                }
            }
        }
    }

    for (auto &elem : str) {
        if (elem.second == true) cout<<elem.first;
        else {
            if (elem.first == '(' || elem.first == ')') cout<<"()";
            else cout<<"[]";
        }
    }
    cout<<endl;
    freopen("CON", "r", stdin);
    system("pause");
}