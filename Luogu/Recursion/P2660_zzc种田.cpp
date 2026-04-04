#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL x, y;
LL ans;

void f(LL a, LL b){
    if(b==0) return;
    if(a>b) swap(a, b);
    LL cnt = b / a;
    ans += cnt*a*4;
    f(a, b%a);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> x >> y;
    f(x, y);
    cout << ans << endl;
    return 0;
}
