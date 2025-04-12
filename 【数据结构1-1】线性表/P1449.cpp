//P1449 ��׺���ʽ
//ѧ��һ������isalpha(char ch), isdigit(char ch), ����boolֵ��٣�����Ҫ����ͷ�ļ�����ʹ�ã�Ŀ����Ҫ�ǽ�ʡʱ��ͼ���ϸ��˼��
#include <iostream>
#include <stack>
using namespace std;
stack<int> s;
char ch;
int num;
int main() {
    while ((ch = getchar()) != '@') {
        if (isdigit(ch)) num = num * 10 + ch - '0';
        else if (ch == '.') {
            s.push(num);
            num = 0;
        }
        else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+' : s.push(a+b); break;
                case '-' : s.push(a-b); break;
                case '*' : s.push(a*b); break;
                case '/' : s.push(a/b); break;
            }
        }
    }
    cout<<s.top()<<endl;
    system("pause");
}