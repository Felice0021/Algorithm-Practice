#include <iostream>
#include <cstring>
using namespace std;

int cnt[10] = {0};

bool check(int x){
    memset(cnt, 0, sizeof cnt);
    while(x){
    int t = x % 10;
    if(t==0) cnt[0]++;
    if(t==2) cnt[2]++;
    if(t==5) cnt[5]++;
    x /= 10;
}
  return cnt[0]>=1 && cnt[2]>=2 && cnt[5]>=1;
}

int main()
{
  int ans = 0;
  for(int i=1; i<=20250412; i++){
    if(check(i)) ans++;
  }

  cout << ans << endl;
  return 0;
}
