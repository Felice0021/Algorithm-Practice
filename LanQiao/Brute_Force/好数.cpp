#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
int ans; 

bool isGood(int x){
  int cnt = 1;
  while(x){
    int t = x % 10;
    if(cnt%2 && t%2==0) return false;
    if(cnt%2==0 && t%2==1) return false; 
    cnt++;
    x /= 10;
  }
  return true;
}

int main(){
  int n; cin >> n;

  for(int i=1; i<=n; i+=2){
    if(isGood(i)) ans++;
  }

  cout << ans << endl;
  return 0;

}
