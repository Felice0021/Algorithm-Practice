#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e4 + 10;
typedef long long LL;
LL x[N], y[N];
LL ans;

int main()
{
  int n; cin >> n;
  for(int i=1; i<=n; i++) cin >> x[i];
  for(int i=1; i<=n; i++) cin >> y[i];

  sort(x+1, x+1+n);
  sort(y+1, y+1+n);

  for(int i=1; i<=n; i++){
    ans += abs(x[i] - y[i]);
  }

  cout << ans << endl;

  return 0;
}
