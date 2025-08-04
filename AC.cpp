#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int dp[505][505];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        memset(dp,0,sizeof(dp));
        int a[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i =0 ; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]) {
                    dp[i][j] = 1;
                    if (i >= 1 && j >= 1) {
                        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    }
                }
                ans = max(ans,dp[i][j]);
            }
        }
        cout << ans << '\n';
    }
}