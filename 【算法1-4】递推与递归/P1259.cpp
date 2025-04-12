//P1259 黑白棋子的移动
////rfind findlastof在查子串时候有区别，暂时还没搞明白，查cpp primer吧
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<string> ans;
void build(string &a) {
    ans.push_back(a);
    if (a.length() >= 10 && a.substr(0, 10) == "oooo****--") {
        string tail = a.substr(10, a.length() - 10);
        //ans.push_back("oooo****--" + tail);
        ans.push_back("ooo--***o*" + tail);
        ans.push_back("ooo*o**--*" + tail);
        ans.push_back("o--*o**oo*" + tail);
        ans.push_back("o*o*o*--o*" + tail);
        ans.push_back("--o*o*o*o*" + tail);
    }
    else {
        int star_pos = a.find('*');//find返回的是unsigned long long下标不是迭代器，复习了
        if (a[star_pos-1] == 'o') {
            int minus_pos = a.find('-');
            a[minus_pos] = 'o', a[minus_pos+1] = '*';
            a[star_pos-1] = '-', a[star_pos] = '-';
        }
        else {
            int back_star_pos = a.find("*o");//find里面也可以填字符串，返回第一个匹配的字符的下标
            a[star_pos-2] = '*', a[star_pos-1] = '*';
            a[back_star_pos] = '-', a[back_star_pos-1] = '-';
        }
        build(a);
    }
}
int main() {
    cin>>n;
    string s1(n, 'o'), s2(n, '*'), s3(2, '-');
    string str = s1 + s2 + s3;
    build(str);
    for (auto elem : ans) cout<<elem<<endl;
    system("pause");
}