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
const int MAXN = 1e5+7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,ans,base = 31,k,n,h1[MAXN],h2[MAXN],p[MAXN],dp[MAXN],m,o1,o2,o3,o4;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll get1(ll l,ll r){
    return (h1[r] - h1[l-1] * p[r-l+1] + 1ll * MOD * MOD)%MOD;
}
ll get2(ll l,ll r){
    return (h2[r] - h2[l-1] * p[r-l+1] + 1ll * MOD * MOD)%MOD;
}
ll sol(ll l,ll r){
    while(l<=r){
        ll mid = (l+r)/2;
        bool ok = false;
        for (ll i = 1;i <= n-mid+1;i++){
            if (get1(i,i+mid-1)==get2(n-(i+mid-1)+1,n-i+1)){
                ok = true;
                break;
            }
        }
        if (ok){
            l = mid+1;
            ans = max(ans,mid);
        }else r = mid - 1;
    }
    return ans;
}
ll random(ll l,ll r){
    return l+rand()%(r-l+1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,cnt,u,v;
    string ss,stt,sss,str,st,s;
    srand(time(NULL));
    vector<ll> adj[256];
    cin >> n;
    cin >> st;
    s = st;
    reverse(s.begin(),s.end());
    s = '$'+s;
    st = '$'+st;
    h1[0] = h2[0] = p[0] = 1;
    for (i = 1;i <= n;i++){
        h1[i] = (h1[i-1]*base+st[i]-'a')%MOD;
        h2[i] = (h2[i-1]*base+s[i]-'a')%MOD;
        p[i] = p[i-1]*base%MOD;
    }
    ans = 0;
    for (i = 1;i <= 50;i++){
        x = random(1,n);
        sol(1,n/x);
        sol(n/x+1,n);
    }
    cout << ans;
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
2 1 3 2 1



3 1 2 2 1
1 2 2 1 3
1 3 1 2 2
1 3 2 2 1

5
abacd
cdaba

ababa

*/
