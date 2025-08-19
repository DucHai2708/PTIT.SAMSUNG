#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
const int maxn = 100005;

ll n, q, a[maxn], tree[4*maxn];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    }
    else {
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        a[idx] += val;
        tree[node] += val;
    }
    else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2*node,start,mid,idx,val);
        }
        else {
            update(2*node+1,mid+1,end,idx,val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(int node, int start, int end, int l, int r) {
    if (end < l or start > r) return 0;
    if (l <= start and end <= r) return tree[node];
    int mid = (start + end) / 2;
    ll p1 = query(2*node,start,mid,l,r);
    ll p2 = query(2*node+1,mid+1,end,l,r);
    return (p1+p2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while (q--) {
        int t, u, v, k;
        cin >> t;
        if (t == 1) {
            cin >> u >> k;
            update(1,1,n,u,k);
        }
        else {
            cin >> u >> v;
            cout << query(1,1,n,u,v) << '\n';
        }
    }
}