#include <iostream> 
#include <cstdio> 
#include <cstring> 
#define FOR(i,a,b) for(int i=a;i<=b;i++) 
#define base 1000000003LL 
#define ll long long 
#define maxn 1000111 
using namespace std; 
ll POW[maxn],hashT[maxn], hashX[maxn]; 

ll getHashT(int i,int j) { 
    return (hashT[j]-hashT[i-1]*POW[j-i+1]+base*base)%base; 
} 
int main() { 
    string T,P; 
    cin >> T >> P; 
    int m=T.size(),n=P.size(); 
    T=" "+T;P=" "+P; 
    POW[0]=1; 
    FOR(i,1,m) POW[i]=(POW[i-1]*26) % base; 
    FOR(i,1,m) hashT[i]=(hashT[i-1]*26+T[i]-'a') % base; 
    for (int i = m; i >= 1; i--) hashX[i]=(hashX[i-1]*26+T[i]-'a') % base; 
    ll hashP=0; 
    FOR(i,1,n) hashP=(hashP*26+P[i]-'a') % base; 
    FOR(i,1,m-n+1) if(hashP==getHashT(i,i+n-1)) printf("%d ",i); 
    for (int len = T.length(); len >= 1; len--) {
        
    }
}