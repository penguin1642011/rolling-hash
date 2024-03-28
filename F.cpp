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
const int MAXN = 4e3+7;
vector<ll> topo;
static ll in[1000];
ll dx[8] = {-1,0,0,1,-1,-1,1,1};
ll dy[8] = {0,-1,1,0,-1,1,-1,1};
static ll Hash,ans,base = 131,k,n,b[MAXN],c[MAXN],a[MAXN],h[MAXN],p[MAXN],dp[MAXN],m,o1,o2,o3,o4;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("ROBOT.INP","r",stdin);
    //freopen("ROBOT.OUT","w",stdout);
    static ll tt,xx,y,x,z,yy,d,j,l,r,lo,rr,i,res,index,note,cnt,pre1[MAXN],pre2[MAXN];
    string ss,stt,sss,str,s,st;
    cin >> st >> s;
    if (st.size()<s.size())swap(st,s);
    n = st.size();
    m = s.size();
    st = '$'+st;
    s = '$'+s;
    p[0] = 1;
    for (i = 1;i <= 26;i++)
    p[i] = p[i-1]*base%MOD;
    for (i = 1;i <= n;i++)
    pre1[i] = pre1[i-1]+p[st[i]-'a'];
    for (i = 1;i <= m;i++)
    pre2[i] = pre2[i-1]+p[s[i]-'a'];
    for (k = 1;k <= n;k++){
        unordered_map<ll,bool> f;
        for (i = 1;i <= m-k+1;i++)
        f[pre2[i+k-1]-pre2[i-1]] = true;
        for (i = 1;i <= n-k+1;i++)
        if (f[pre1[i+k-1]-pre1[i-1]]){
            ans = k;
            break;
        }
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
3
1
1 2 2
*/ 
