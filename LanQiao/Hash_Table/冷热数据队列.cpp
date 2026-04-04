#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

list<int> q1, q2;
unordered_map<int, list<int>::iterator> mp1, mp2;
int n1, n2, m;


int main()
{
  cin >> n1 >> n2 >> m;

  while(m--){
    int p; cin >> p;

    if(mp1.count(p)){
      // 删除
      q1.erase(mp1[p]);
      mp1.erase(p);
      // 移动
      q1.push_front(p);
      mp1[p] = q1.begin();
    }

    else if(mp2.count(p)){
      // 删除
      q2.erase(mp2[p]);
      mp2.erase(p);
      // 移动
      q1.push_front(p);
      mp1[p] = q1.begin();
    }

    else{
      q2.push_front(p);
      mp2[p] = q2.begin();
    }

    if(q1.size()>n1){
      // 删除
      int p = *q1.rbegin();
      mp1.erase(p);
      q1.pop_back();
      // 移动
      q2.push_front(p);
      mp2[p] = q2.begin();
    }

    if(q2.size()>n2){
      int p = *q2.rbegin();
      mp2.erase(p);
      q2.pop_back();
    }
    
  }

  for(auto p : q1) cout << p << " ";
  cout << endl;
  for(auto p : q2) cout << p << " ";
 
  return 0;
}
