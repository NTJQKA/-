//P1449 后缀表达式
//学了一个函数isalpha(char ch), isdigit(char ch), 返回bool值真假，不需要引入头文件即可使用，目的主要是节省时间和减少细节思考
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