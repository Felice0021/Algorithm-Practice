#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
int n, s, a, b;
int cnt;
int A[N];

int main(){
    cin >> n >> s >> a >> b;
    int t = a + b;
    for(int i=1; i<=n; i++){
        int x, y; cin >> x >> y;
        if(x<=t) A[++cnt] = y;
    }

    sort(A+1, A+1+cnt);

    int sum = 0;
    int ans = 0;
    for(int i=1; i<=cnt; i++){
        sum += A[i];
        if(sum<=s) ans++;
    }

    cout << ans << endl;
    return 0;
}
