#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;

    string ans;
    
    for(char c : s){
        while(k && !ans.empty() && ans.back()>c) {
            ans.pop_back();
            k--;
        }
        ans.push_back(c);
    }

    // 剩余递增序列
    while(k) {
        ans.pop_back();
        k--;
    }

    while(ans.size()>1 && ans[0]=='0') ans.erase(0, 1);

    cout << ans << endl;
}
