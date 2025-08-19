#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    int x, y, z;
    cin >> x >> y >> z;
    int dj = 1, d1 = 2;
    for (int i = 0; i < y-1; i++) {
        dj += d1;
        ++d1;
    }
    int d2 = y, res = dj;
    for (int i = 0; i < x-1; i++) {
        res += d2;
        ++d2;
    }
    cout << res;

}