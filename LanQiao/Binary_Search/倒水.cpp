#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, k;
int Max;

bool check(int x){
  for(int i=1; i<=k; i++){
    int t = 0; // 前一个杯子可倒给下一个杯子的水量
    for(int j=i; j<=n; j+=k){
      // a[j] += t; a[N]是全局变量， 不可以直接加t，否则会改变值
      if(a[j] + t < x) return false;
      else{
        t = a[j] + t - x;
      }
    }
  }
  return true;
}

int main()
{
  cin >> n >> k;
  for(int i=1; i<=n; i++){
    cin >> a[i];
    Max = max(a[i], Max);
  }
  
  int l = 1, r = Max ;
  while(l<r){
    int mid = (l + r + 1) / 2;
    if(check(mid)) l = mid;
    else r = mid - 1;
  } 

  cout << l << endl;
  return 0;
}
