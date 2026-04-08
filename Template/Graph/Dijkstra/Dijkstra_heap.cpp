#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, int> PII;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
int n, m, s;
vector<PII> edges[N];
LL dist[N];

void dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});

    while(heap.size()){
        auto [d, u] = heap.top();
        heap.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : edges[u]){
            if(dist[v] > dist[u] + w){
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
        edges[u].push_back({v, w});
    }

    dijkstra();

    for(int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}
