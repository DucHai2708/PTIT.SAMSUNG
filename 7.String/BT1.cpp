#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
using ll = long long;
const int Mod = 1e9+7;

vector<int> buildLPS(string pat) {
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    for (int i = 1; i < m;) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        }
        else {
            if (len != 0) len = lps[len-1];
            else lps[i++] = 0;
        }
    }
    return lps;
}

void KMP(string txt, string pat) {
    int n = txt.size(), m = pat.size();
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;j++;
        }
        if (j == m) {
            cout << i-j+1 << ' ';
            j = lps[j-1];
        }
        else if (i < n and txt[i] != pat[j]) {
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //code here
    string txt, pat;
    cin >> txt >> pat;
    KMP(txt,pat);
}