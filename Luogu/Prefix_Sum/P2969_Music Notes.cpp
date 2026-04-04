#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

int n, q;
int f[N]; // 前缀和数组

int main(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        f[i] = f[i-1] + x;
    }

    while(q--){
        int t; cin >> t;
        int l = 1, r = n;
        while(l<r){
            int mid = (l + r) / 2;
            if(f[mid]>t) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }

    return 0;
}
