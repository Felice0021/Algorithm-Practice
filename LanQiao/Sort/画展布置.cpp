#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
int n, m;
LL a[N];
LL ans = 1e10;

int main(){
  cin >> n >> m;
  for(int i=1; i<=n; i++) cin >> a[i];

  sort(a+1, a+n+1);

  for(int i=1; i+m-1<=n; i++){
    ans = min(a[i+m-1]*a[i+m-1] - a[i]*a[i], ans);
  }

  cout << ans << endl;

  return 0;
}
