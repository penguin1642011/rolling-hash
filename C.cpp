#include<bits/stdc++.h>
/*
        penguin yes cop code
        https://codeforces.com/profile/Tuanhaiphong2
*/
using namespace std;
#define x1 o1
#define x2 o2
#define y1 o3
#define y2 o4
#define ll long long
#define fi first
#define se second
const int MOD = 998244353;
const int MAXN = 1e5+7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,ans,base = 131,k,n,b[MAXN],a[MAXN],h1[MAXN],h2[MAXN],h3[MAXN],p[MAXN],dp[MAXN],m,o1,o2,o3,o4;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll get1(ll l,ll r){
    return (h1[r] - h1[l-1]*p[r-l+1] + 1ll * MOD * MOD)% MOD;
}
ll get2(ll l,ll r){
    return (h2[r] - h2[l-1] * p[r-l+1] + 1ll * MOD * MOD)% MOD;
}
ll get3(ll l,ll r){
    return (h3[r] - h3[l-1] * p[r-l+1] + 1ll * MOD * MOD)% MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,cnt,pre1[MAXN],pre2[MAXN];
    string ss,stt,sss,str,s,st;
    cin >> n;
    p[0] = h1[0] = h2[0] = h3[0] = 1;
    for (i = 1;i <= n;i++){
        cin >> a[i];
        h1[i] = (h1[i-1]*base + a[i])%MOD;
    }
    for (i = 1;i <= n;i++)
    h2[i] = (h2[i-1]*base+a[n-i+1])%MOD;
    for (i = 1;i <= n;i++){
        cin >> x;
        p[i] = p[i-1]*base%MOD;
        h3[i] = (h3[i-1]*base + x)%MOD;
    }
    vector<ll> v;
    for (k = 1;k <= n;k++){
        bool b1 = false,b2 = false;
        if ((n-k)%2==0){
            if (get2(n-k+2,n)==get3(n-k+2,n))b1 = true;
        }else if (get1(1,k-1)==get3(n-k+2,n))b1 = true;
        if (get1(k,n)==get3(1,n-k+1))b2 = true;
        if (b1&&b2)v.push_back(k);
        //cout << k << ' ' << b1 << ' ' << k << '\n';
    }
    cout << v.size() << '\n';
    for (i = 0;i < v.size();i++)
    cout << v[i] << ' ';
    return (0^0)&(200+10);
}
/*
  4 9 2 4
1 0 0 0 0
9 0 1 1 1
7 0 1 1 1
3 0 1 1 1
4 0 1 1 2
5 6
-2 3 2 3 3
-2 1 3 7 10
 T

 5
5 5 5 4 5
4 5 5 5 5
    1 1 1

1 2 4 5 20
0 1 
5
1 2 3 1 2
3
1
1 2 2
*/ 