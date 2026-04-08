#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef long long LL;
vector<int> tr1[N], tr2[N];
int n, m;
LL c[N], d[N];
LL ans;

struct Node{
  int u1, u2;
  LL dep;
};

void bfs(){
  queue<Node> q;
  q.push({1, 1, 1});

  while(q.size()){
    Node now = q.front();
    q.pop();

    int u1 = now.u1, u2 = now.u2;
    LL dep = now.dep;
    ans = max(ans, dep);

    for(int v1 : tr1[u1]){
      for(int v2 : tr2[u2]){
        if(c[v1] == d[v2]){
          q.push({v1, v2, dep + 1});
        }
      }
    }
  }
}

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> c[i];
  for(int i=1; i<=m; i++) cin >> d[i];

  if(c[1] != d[1]){
    cout << 0 << endl;
    return 0;
  }

  for(int i=1; i<n; i++){
    int a, b; cin >> a >> b;
    tr1[a].push_back(b);
  }

  for(int i=1; i<m; i++){
    int a, b; cin >> a >> b;
    tr2[a].push_back(b);
  }

  bfs();

  cout << ans << endl;
  return 0;

}
