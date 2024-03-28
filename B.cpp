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
const int MOD = 1e9 +7;
const int MAXN = 1e6+7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,ans,base = 256,k,n,h[MAXN],p[MAXN],dp[MAXN],m,o1,o2,o3,o4;
ll get(ll l,ll r){
    return (h[r] - h[l-1] * p[r-l+1] + 1ll * MOD * MOD)%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,cnt,u,v;
    string ss,stt,sss,str,st,s;
    cin >> n >> tt;
    cin >> s;
    s = '$'+s;
    h[0] = p[0] = 1;
    for (i = 1;i <= n;i++){
        h[i] = (h[i-1]*base+s[i])%MOD;
        p[i] = p[i-1]*base%MOD;
    }
    cnt = 1;
    unordered_map<ll,unordered_map<ll,ll>> f;
    unordered_map<ll,ll> aa;
    k = n/tt;
    while(tt--){
        cin >> st;
        Hash = 0;
        for (i = 0;i < st.size();i++)
        Hash = (Hash*base+st[i])%MOD;
        f[Hash][++aa[Hash]] = cnt++;
    }
    for (i = 1;i <= n-k+1;i+=k){
        x = get(i,i+k-1);
        cout << f[x][aa[x]--] << ' ';
    }
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
*/
