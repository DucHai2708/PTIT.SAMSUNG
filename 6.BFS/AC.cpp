#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

map<string,int> mp;
map<string,int> mtp;

string ror(string s) {
    string t = s;
    t[0] = 'x';
    t[1] = s[1]; t[2] = s[5]; t[3] = s[2];
    t[4] = s[4]; t[5] = s[9]; t[6] = s[6]; t[7] = s[3];
    t[8]= s[8]; t[9] = s[10]; t[10] = s[7];
    return t;
}

string rol(string s) {
    string t = s;
    t[0] = 'x';
    t[1] = s[4]; t[2] = s[1]; t[3] = s[3];
    t[4] = s[8]; t[5] = s[5]; t[6] = s[2]; t[7] = s[7];
    t[8]= s[9]; t[9] = s[6]; t[10] = s[10];
    return t;
}

string vror(string s) {
    string t = s;
    t[0] = 'x';
    t[1] = s[1]; t[2] = s[3]; t[3] = s[7];
    t[4] = s[4]; t[5] = s[2]; t[6] = s[6]; t[7] = s[10];
    t[8]= s[8]; t[9] = s[5]; t[10] = s[9];
    return t;
}

string vrol(string s) {
    string t = s;
    t[0] = 'x';
    t[1] = s[2]; t[2] = s[6]; t[3] = s[3];
    t[4] = s[1]; t[5] = s[5]; t[6] = s[9]; t[7] = s[7];
    t[8]= s[4]; t[9] = s[8]; t[10] = s[10];
    return t;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    string s;
    s = "x" + s;
    for (int i = 1; i <= 10; i++) {
        string t; cin >> t;
        s = s + t;
    }
    string st = s;
    string ed = "x1238004765";
    queue<pair<string,int>> q1, q2;
    q1.push({st,0}); q2.push({ed,0});
    mp[st]++; mtp[ed]++;
    while (!q1.empty()) {
        pair<string,int> p = q1.front(); q1.pop();
        if (p.fi == ed) {
            cout << p.se << '\n';
            return 0;
        }
        if (p.se > 15) {
            break;
        }
        string xr = ror(p.fi);
        string xl = rol(p.fi);
        if (!mp[xr]) {
            q1.push({xr,p.se+1});
            mp[xr] = p.se+1;
        }
        if (!mp[xl]) {
            q1.push({xl,p.se+1});
            mp[xl] = p.se+1;
        }
    }
    while (!q2.empty()) {
        pair<string,int> p = q2.front(); q2.pop();
        if (mp[p.fi] != 0) {
            cout << mp[p.fi] + p.se << '\n';
            return 0;
        }
        string xr = vror(p.fi);
        string xl = vrol(p.fi);
        if (!mtp[xr]) {
            q2.push({xr,p.se+1});
            mtp[xr] = p.se+1;
        }
        if (!mtp[xl]) {
            q2.push({xl,p.se+1});
            mtp[xl] = p.se+1;
        }
    }
    cout << -1 << '\n';
}