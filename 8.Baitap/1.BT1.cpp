#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int countDivisors(int n) {
    int ans = 0;
    for (int i = 1;i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i*i ==n) ans += 1;
            else ans += 2;
        }
    }
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        cout << countDivisors(n) << '\n';
    }
}