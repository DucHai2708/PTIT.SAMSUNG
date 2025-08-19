#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int dist[1000005];

int tn(int a[]) {
    int res = 0;
    for (int i = 1; i <= 6; i++) res = res * 10 + a[i];
    return res;
}

int ror(int x) {
    int a[7];
    for (int i = 6; i >= 1; i--) {
        a[i] = x % 10;
        x /= 10;
    }
    int b[7];
    b[1] = a[1]; b[2] = a[5]; b[3] = a[2];
    b[4] = a[4]; b[5] = a[6]; b[6] = a[3];
    int res = tn(b);
    return res;
}

int rol(int x) {
    int a[7];
    for (int i = 6; i >= 1; i--) {
        a[i] = x % 10;
        x /= 10;
    }
    int b[7];
    b[1] = a[4]; b[2] = a[1]; b[3] = a[3];
    b[4] = a[5]; b[5] = a[2]; b[6] = a[6];
    int res = tn(b);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int a[7], b[7];
    for (int i = 1; i <= 6; i++) cin >> a[i];
    for (int i = 1; i <= 6; i++) cin >> b[i];
    int st = tn(a), ed = tn(b);
    memset(dist,0,sizeof(dist));
    queue<pair<int,int>> q;
    q.push({st,0}); dist[st] = 1;
    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        if (p.fi == ed) {
            cout << p.se << '\n';
            return 0;
        }
        int xr = ror(p.fi);
        int xl = rol(p.fi);
        if (!dist[xr]) {
            q.push({xr,p.se+1});
            dist[xr] = 1;
        }
        if (!dist[xl]) {
            q.push({xl,p.se+1});
            dist[xl] = 1;
        }
    }
    cout << -1 << '\n';
}