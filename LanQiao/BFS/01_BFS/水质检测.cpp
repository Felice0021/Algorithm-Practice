#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e6 + 10;
int n;
char c[2][N];
int dist[2][N]; // 确定最短路径 01bfs 
bool vis[2][N]; // 标记该点是否找到最短路径

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs(int x, int y){
  int ret = 0;
  memset(dist, 0x3f, sizeof dist); 
  deque<PII> q;
  q.push_front({x, y});
  dist[x][y] = 0; // 第一个#位置点进入bfs， dist=0

  while(q.size()){
    auto t = q.front(); q.pop_front();
    int a = t.first, b = t.second;
    if(vis[a][b]) continue; // 已找到最短路径的点跳过

    vis[a][b] = true; // 标记已找到最短路径
    if(c[a][b] == '#') ret = max(ret, dist[a][b]); // 最小代价更新为dist[a][b]中的最大值，表示走到最右一个#

    for(int k=0; k<4; k++){
      int x = a + dx[k];
      int y = b + dy[k];
      if(x<0 || x>=2 || y<0 || y>=n || vis[x][y]) continue;

      int w = c[x][y]=='#' ? 0 : 1;
      dist[x][y] = min(dist[x][y], dist[a][b]+w); // 更新走到x，y点的最小代价路径

      if(w) q.push_back({x, y});
      else q.push_front({x, y});
    }

  }

  return ret;
  
}

int main(){
  cin >> c[0] >> c[1];
  n = strlen(c[0]);

  for(int j=0; j<n; j++){
    if(c[0][j] == '#'){
      cout << bfs(0, j) << endl;
      return 0;
    }

    if(c[1][j] == '#'){
      cout << bfs(1, j) << endl;
      return 0;
    }
  }

  cout << 0 << endl; // 一个检测器都没有

  return 0;
}
