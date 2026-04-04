#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
typedef long long LL;
int n, m, k;
int f[N][N]; // 差分数组

void insert(int x1, int y1, int x2, int y2, int k){
    f[x1][y1] += k;
    f[x1][y2+1] -= k;
    f[x2+1][y1] -= k;
    f[x2+1][y2+1] +=k;
}

int main(){
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int x, y, z; cin >> x >> y >> z;
        insert(x, y, x, y, z);
    }

    LL ans = 0;
    for(int x1=1; x1<=n-k+1; x1++){
        for(int y1=1; y1<=n-k+1; y1++){
            ans += abs(f[x1][y1]);
            int x2 = x1 + k - 1, y2 = y1 + k - 1;
            insert(x1, y1, x2, y2, -f[x1][y1]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(f[i][j]!=0){
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
