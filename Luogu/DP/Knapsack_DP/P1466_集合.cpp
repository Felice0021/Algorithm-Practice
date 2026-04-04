#include <bits/stdc++.h>

using namespace std;

const int N = 44, M = 1000;
typedef long long LL;
LL f[M];
int n;

int main(){
    cin >> n;
    int sum = n * (n+1) / 2;
    if(sum%2){
        cout << 0 << endl;
        return 0;
    }

    f[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=sum/2; j>=i; j--)
            f[j] = f[j] + f[j-i];
    }

    cout << f[sum/2] / 2<< endl;
    
    return 0;
}
