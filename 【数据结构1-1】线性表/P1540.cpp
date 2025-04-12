#include <bits/stdc++.h>
using namespace std;
int M, N, ans;
set<int> SET;
set<pair<int, int>> Q;//nowtime, word
int main() {
    int nowtime = 0;
    cin>>M>>N;
    while (N--) {
        nowtime++;
        int word = 0;
        cin>>word;
        if (SET.find(word) == SET.end()) {
            ans++;
            if (SET.size() >= M) {
                auto i = Q.begin();
                int del_word = (*i).second;
                Q.erase(i);
                SET.erase(del_word);
            }
            Q.insert({nowtime, word});
            SET.insert(word);
        }
        else continue;
    }
    cout<<ans<<endl;
    system("pause");
}