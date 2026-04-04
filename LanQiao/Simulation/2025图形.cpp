#include <iostream>
using namespace std;
int main()
{
  int a[4]= {2, 0, 2, 5};
  int h, w; cin >> h >> w;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << a[(j + i) % 4];
    }
    cout << endl;
  }
  return 0;
}
