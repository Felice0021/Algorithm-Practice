#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int N = 1010;
int w[N];
int n;
vector<int> edges[N]; // 创建树
// bool f[N][N]; // f[x][j]状态表示x节点是否能向上提供j单位成品
bitset<N> f[N]; // bitset优化

void dfs(int x, int fa){
  // 初始化
  f[x][0] = true;
  // 叶子结点直接向上返回
  if(x!=1 && edges[x].size()==1){
    f[x][w[x]] = true;
    return;
  }

  for(auto y : edges[x]){
    if(y==fa) continue; // 只遍历x的孩子
    dfs(y, x);

    // for(int j=w[x]; j>=0; j--){
    //   for(int k=min(w[y], j); k>=0; k--){
    //     f[x][j] = f[x][j] || (f[y][k] && f[x][j-k]); // x节点已经满足更大j 或者 x节点已满足j-k单位且y节点能满足k单位
    //   }
    // }

    // bitset优化两层for循环
    bitset<N> tmp = f[x];
    for(int k=w[y]; k>=0; k--){
      if(f[y][k]) f[x] |= tmp << k;
    }
  }

}

int main()
{
  cin >> n;
  for(int i=1; i<=n; i++) cin >> w[i];

  for(int i=1; i<n; i++){
    int a, b; cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1, 0); // 从根节点开始遍历，同时传入父节点

  for(int i=w[1]; i>=0; i--){
    if(f[1][i]){
      cout << i << endl;
      break;
    }
  }

  return 0;
}
