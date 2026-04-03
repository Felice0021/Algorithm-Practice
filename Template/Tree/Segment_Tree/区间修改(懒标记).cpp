#include <iostream>

using namespace std;

#define lc p << 1
#define rc p << 1 | 1 // p*2+1
typedef long long LL;
const int N = 5e5 + 10;
int n, m;
LL a[N];



struct node {
    int l, r;
    LL sum, add; // add-懒标记
} tr[N<<2];

void pushup(int p) {
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void lazy(int p, LL add) {
    int l = tr[p].l, r = tr[p].r;
    tr[p].sum += add * (r - l + 1);
    tr[p].add += add;
}

void pushdown(int p) {
    LL add = tr[p].add;
    lazy(lc, add);
    lazy(rc, add);
    tr[p].add = 0;
}

void build(int p , int l, int r) {
    tr[p] = {l, r, a[l], 0};
    if (l==r) return;

    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid+1, r);

    pushup(p); // 记得更新sum值
}

// 区间修改--加k
void modify(int p, int x, int y, LL k) {
    int l = tr[p].l, r = tr[p].r;
    int mid = (l + r) >> 1;
    if (x<=l && y>=r) {
        lazy(p, k); // 懒标记
        return; //记得返回
    }

    pushdown(p); // 懒标记下放，传给子树
    if (x<=mid) modify(lc, x, y, k);
    if (y>mid) modify(rc, x, y, k);

    pushup(p); // 更新父节点
}

// 区间查询
LL query(int p, int x, int y) {
    int l = tr[p].l, r = tr[p].r;
    int mid = (l + r) >> 1;

    if (x<=l && y>=r) return tr[p].sum;

    pushdown(p); // 记得下放懒标记

    LL sum = 0;
    if (x<=mid) sum += query(lc, x, y);
    if (y>mid) sum += query(rc, x, y);
    return sum;
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];

    build(1, 1, n); // 创建树

    while (m--) {
        int op; cin >> op;
        if (op==1) {
            int x, y; LL k;
            cin >> x >> y >> k;
            modify(1, x, y, k);
        }
        else {
            int x, y; cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }

    return 0;
}
