#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int C[505][505];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        memset(C,0,sizeof(C));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    C[i][j] = 1;
                    if (i >= 1 && j >= 1) {
                        C[i][j] = min(C[i-1][j-1]+1, min(C[i-1][j]+1, C[i][j-1]+1));
                    }
                }
                ans = max(ans,C[i][j]);
            }
        }
        cout << ans << '\n';
    }
}