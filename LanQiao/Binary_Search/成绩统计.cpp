#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n, k;
LL t;
LL a[N];
LL sum1, sum2;
LL tmp[N];

bool check(int x){
  for(int i=1; i<=x; i++){
    tmp[i] = a[i];
  }

  sort(tmp+1, tmp+x+1);

  sum1 = 0, sum2 = 0;

  for(int i=1; i<k; i++){
    sum1 += tmp[i];
    sum2 += tmp[i]*tmp[i];
  }

  for(int i=1; i+k-1<=x; i++){
    int j = i + k - 1;
    sum1 = sum1 - tmp[i-1] +tmp[j];
    sum2 = sum2 - tmp[i-1]*tmp[i-1] + tmp[j]*tmp[j];
    if(k*sum2-sum1*sum1 < k*k*t) return true;
  }

  return false;
}

int main(){
  cin >> n >> k >> t;
  for(int i=1; i<=n; i++) cin >> a[i];
  int ans = -1;
  int l = 1, r = n;
  while(l<r){
    int mid = (l + r) / 2;
    if(check(mid)){
      ans = mid;
      r = mid;
    }
    else l = mid + 1;
  }
  

  cout << ans << endl;
  return 0;
}
