#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII; // 按<距离， 点>， 方便堆排序
const int N = 1e5 + 10;

vector<PII> edges[N];
LL dist[N];
int n, m, s;

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});

    while(heap.size()){
        auto [d, u] = heap.top();
        heap.pop();

        if(d > dist[u]) continue;
        
        for(auto [w, v] : edges[u]){
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u] + w;
                heap.push({dist[v], v});
            }
        }
    }
}

int main(){
    cin >> n >> m >> s;
    for(int i=1; i<=m; i++){
        int u, v; LL w;
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
    }

    dijkstra();
    
    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}
