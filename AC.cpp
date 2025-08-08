#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
ll Mod = 1e9+7;

struct matrix{
    ll f[2][2];
    matrix() {
        f[0][0] = f[0][1] = f[1][0] = 1;
        f[1][1] = 0;
    }
};

typedef struct matrix matrix;

ll mul(ll a, ll b) {
    ll res = 0;
    a %= Mod;
    while (b) {
        if (b % 2) res = (res + a) % Mod;
        a = (a * 2) % Mod;
        b /= 2;
    } 
    return res;
}

matrix operator*(const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c.f[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.f[i][j] = (c.f[i][j] + mul(a.f[i][k],b.f[k][j]) % Mod) % Mod;
            }
        }
    }
    return c;
}

matrix power(matrix a, ll n) {
    if (n == 1) return a;
    matrix x = power(a,n/2);
    x = x * x;
    if (n % 2) return a*x;
    return x;
}

 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        ll n, base; cin >> n >> base;
        Mod = base;
        matrix a;
        matrix ans = power(a,n);
        cout << ans.f[0][0] << '\n';
    }
}