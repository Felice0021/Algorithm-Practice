#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
LL ans;
LL n, s; 
LL f[N];
int pos;

struct Node{
  LL p, c;
} Solider[N];

bool cmp(Node& a, Node& b){
  return a.c < b.c;
}

int main(){
  cin >> n >> s;
  for(int i=1; i<=n; i++){
    cin >> Solider[i].p >> Solider[i].c;
  }

  sort(Solider+1, Solider+n+1, cmp);

  for(int i=1; i<=n; i++){
    f[i] = f[i-1] + Solider[i].p;
  }

  for(int i=1; i<=n; i++){
    if(f[n] - f[i-1] < s){
      pos = i;
      break;
    }
  }

  ans += s * Solider[pos-1].c;

  for(int i=pos; i<=n; i++){
    ans += Solider[i].p * (Solider[i].c - Solider[pos-1].c);
  }


  cout << ans << endl;

  return 0;
}

