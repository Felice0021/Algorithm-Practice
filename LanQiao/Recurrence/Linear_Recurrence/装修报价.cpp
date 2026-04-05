#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
typedef long long LL;
int n;
LL a[N];
LL ans;
LL f[N]; // 前缀异或和数组

LL qpow(LL a, LL b){
  LL res = 1;
  while(b){
    if(b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int main(){
  cin >> n;

  for(int i=1; i<=n; i++){
    int a; cin >> a;
    f[i] = f[i-1] ^ a;
  }
  for(int i=1; i<n; i++){
    ans += (2 * qpow(3, n-i-1) * f[i]) % MOD;
  }

  ans = (ans + f[n]) % MOD;

  cout << ans << endl;

  return 0;
}
