#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int maxn = 100005;
const int Mod = 1e9+7;
using ll = long long;

ll n, q, a[maxn], f[maxn], bit1[maxn], bit2[maxn];

void update(ll *bit, int u, int v) {
    int idx = u;
    while (idx <= n) {
        bit[idx] += v;
        idx += (idx & (-idx));
    }
}

ll getSum(ll *bit, int p) {
    int idx = p; ll ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(f,0,sizeof(f));
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));

        for (int i = n; i >= 1; i--) {
            f[i] = getSum(bit1,a[i]-1);
            update(bit1,a[i],1);
        }

        ll ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += getSum(bit2,a[i]-1);
            update(bit2,a[i],f[i]);
        }
        
        cout << ans << '\n';
    }
}