#include <iostream>
using namespace std;

bool check(int x){
  int sum = 0;
  while(x){
    sum += x % 10;
    x /= 10;
  }
  return !(sum % 5);
}

int main()
{
  int ans = 0;
  for(int i=1; i<=202504; i++){
    if(check(i)) ans++;
  }

  cout << ans << endl;
  return 0;
}
