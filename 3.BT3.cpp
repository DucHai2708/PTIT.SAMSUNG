#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

ll legendre(ll n, ll p) {
    ll res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}

map<ll,int> pt(ll n) {
    map<ll,int> mp;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                mp[i]++;
                n /= i;
            }
        }
    }
    if (n > 1) mp[n]++;
    return mp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        ll n, k;
        cin >> n >> k;
        map<ll,int> mp = pt(k);
        ll m = LLONG_MAX;
        for (auto x : mp) {
            ll pa = legendre(n,x.fi);
            m = min(m,pa/x.se);
        }
        cout << m << '\n';
    }
}