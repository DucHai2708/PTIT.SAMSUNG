#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
ll Mod = 1e9+7;

struct matrix {
    ll F[2][2];
    matrix() {
        F[0][0] = F[0][1] = F[1][0] = 1;
        F[1][1] = 0;
    }
};

typedef struct matrix matrix;

ll multiply(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b % 2 ==  1) {
            res = (res + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return res;
}

matrix operator * (const matrix &a, const matrix &b) {
    matrix c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++){
            c.F[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                c.F[i][j] = (c.F[i][j] + multiply(a.F[i][k],b.F[k][j],Mod)) % Mod;
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
        matrix m;
        matrix ans = power(m,n);
        cout << ans.F[0][0] << '\n';
    }
}   