//P1241 ��������
//����Ⲣ����Ҫ����insert����Ϊû�к�������Ҫ��ֱ�Ӵ�ӡ����ģ����Դ��ַ���ʱ����ʲô���ݽṹ������
#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);
    vector<pair<char, bool>> str;
    stack<int> match;
    /*char ch;
    while ((ch = getchar()) != '\n') str.push_back({ch, false});*/
    //������е�˵����getchar����û��ȫ�����ף���֪��oj�϶���Ľ�β�ǲ���'\n'�����ڱ���freopen�ܵ�ʱ����\n�ж���ֹ����
    //while (ch = getchar())���ҵı����ܣ��ò����κν��
    string tmp;
    cin>>tmp;
    for (auto &elem : tmp) str.push_back({elem, false}); 
    //ֻ�����ַ������룬������������ܹ�����������

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