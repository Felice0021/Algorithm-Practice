// 洛谷 P4537_矩形
// 思路：模拟，搜索
#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int a, b;
int ans;
bool vis[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int i, int j){
    if(i==0 || i==a || j==0 || j==b ){
        ans++;
        return;
    }

    vis[i][j] = true;

    for(int k=0; k<4; k++){
        int x = i + dx[k], y = j + dy[k];
        if(!vis[x][y]) dfs(x, y);
    }

    vis[i][j] = false;
}

int main(){
    cin >> a >> b;

    // 从上边进入
    for(int j=1; j<b; j++){
        vis[0][j] = true;
        dfs(1, j);
        vis[0][j] = false;
    }

    // 从左边进入
    for(int i =1; i<a; i++){
        vis[i][0] = true;
        dfs(i, 1);
        vis[i][0] = false;
    }

    cout << ans << endl;
    return 0;
}
