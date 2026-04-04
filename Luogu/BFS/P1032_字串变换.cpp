#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 25;
string a, b;
string x[N], y[N];
unordered_map<string, int> dist; // 哈希表记录变换步数
int n; // 记录变换规则个数

int bfs(){
    if(a==b) return 0;

    queue<string> q;
    q.push(a);
    dist[a] = 0;
    
    while(q.size()){
        string s = q.front(); q.pop();
        
        if(dist[s]>=10) return -1;

        // 变换字符串
        for(int i=0; i<n; i++){
            int pos = 0; // 字符变换位置
            while(s.find(x[i], pos) != -1){
                pos = s.find(x[i], pos);
                // 拼接
                string tmp = s.substr(0, pos) + y[i] + s.substr(pos + x[i].size());

                pos++;

                if(dist.count(tmp)) continue;
                dist[tmp] = dist[s] + 1;
                q.push(tmp);

                if(tmp==b) return dist[tmp];
            }    
        }
        }
    return -1;
}

int main(){
    cin >> a >> b;
    
    while(cin >> x[n] >> y[n]) n++;

    int ans = bfs();
    
    if(ans==-1) cout << "NO ANSWER!" << endl;
    else cout << ans << endl;

    return 0;
}
