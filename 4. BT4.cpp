#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
const int maxn = 105;

ll n, m, a[maxn][maxn][maxn], bit[maxn][maxn][maxn];

void update(ll x, ll y, ll z, ll w) {
    ll v = w - a[x][y][z];
    a[x][y][z] = w;
    for (int i = x; i <= n; i += (i & (-i))) {
        for (int j = y; j <= n; j += (j & (-j))) {
            for (int k = z; k <= n; k += (k & (-k))) {
                bit[i][j][k] += v;
            }
        }
    }
}
 
ll getSum(ll x, ll y, ll z) {
    ll ans = 0;
    for (int i = x; i > 0; i -= (i & (-i))) {
        for (int j = y; j > 0; j -= (j & (-j))) {
            for (int k = z; k > 0; k -= (k & (-k))) {
                ans += bit[i][j][k];
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) 
    {
        memset(a,0,sizeof(a));
        memset(bit,0,sizeof(bit));
        cin >> n >> m;
        while (m--) {
            string s; ll x, y, z, w, o, l, m;
            cin >> s;
            if (s == "UPDATE") {
                cin >> x >> y >> z >> w;
                update(x,y,z,w);
            }
            else {
                cin >> x >> y >> z;
                cin >> o >> l >> m;
                cout << getSum(o,l,m) - getSum(x-1,l,m) - getSum(o,y-1,m) - getSum(o,l,z-1) + getSum(x-1,y-1,m) + getSum(o,y-1,z-1) + getSum(x-1,l,z-1) - getSum(x-1,y-1,z-1) << '\n';
            }
        }
    }   
}