#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

int C[6005][6005];

int a, b, c, d , e;

bool check(int x) {
    for (int i = 1; i+x-1 <= a; i++) {
        for (int j = 1; j+x-1 <= b; j++) {
            int s = C[i+x-1][j+x-1] + C[i-1][j-1] - C[i+x-1][j-1] - C[i-1][j+x-1];
            if (s <= e) return true;
        }
    }
    return false;
}  

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    cin >> a >> b >> c >> d >> e;
    int arr[a+1][b+1];
    memset(arr,0,sizeof(arr));
    memset(C,0,sizeof(C));
    int x, y;
    while (c--) {
        cin >> x >> y;
        arr[x][y] = 1;
    }
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            C[i][j] = arr[i][j] + C[i-1][j] + C[i][j-1] - C[i-1][j-1];
        }
    }
    // Thao tác / d rồi * d là để tìm bội lớn nhất của d <= 1 giá trị tìm đc
    int res = 0;
    int l = d, r = min(a,b) / d * d;
    while (l <= r) {
        int m = (l + r) / 2;
        int x = m / d * d;
        if (check(x)) {
            res = x;
            l = x + d;
        }
        else {
            r = x - d;
        }
    }
    cout << res << '\n';
}