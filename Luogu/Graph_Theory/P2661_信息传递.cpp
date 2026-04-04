#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
int to[N]; // 存单向边
int pos[N]; // 记录该点处于遍历过程的第几步
int vis[N]; // 标记该点是否访问，0-未访问，1-访问中， 2-访问完成
int ans = N;

void dfs(int u, int step){
    vis[u] = 1;
    pos[u] = step;
    int v = to[u];
    if(!vis[v]) dfs(v, step+1);
    else if(vis[v]==1) ans = min(ans, step-pos[v]+1);
    vis[u] = 2;
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> to[i];

    // dfs遍历找最小环
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs(i, 1);
    }

    cout << ans << endl;
    return 0;
}
