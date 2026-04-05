#include <bits/stdc++.h>

using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    while(k--){
      int x = (b + c) / 2;
      int y = (a + c) / 2;
      int z = (a + b) / 2;
      a = x; b = y; c = z;
      if(a==b && b==c) break;
    }
    cout << a << " " << b << " " << c << endl;
  }

  return 0;
}
