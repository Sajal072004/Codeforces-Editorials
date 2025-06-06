/*-----------------------------------------------*/
/* Everything that kills me makes me feel alive. */
/* Email: <a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="127060777379627e676152747d6a7f737b7e3c717d7f">[email&#160;protected]</a>                  */
/* Author: wzj_zhzx_oicon / BreakPlus            */
/*-----------------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<pair<ll,ll>,ll> P3;
typedef pair<pair<ll,ll>,pair<ll,ll> >P4;
#define mkp make_pair
#define fi first
#define se second
#define popcnt __builtin_popcountll
#define pb emplace_back
//#define FastIO
//#define OIcontest
const ll mod=998244353;
const ll maxn=500005;

inline ll read(){
	ll x=0,f=1; char ch=getchar(); while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar(); return x*f;
}
inline ll lowbit(ll x){ return x&-x; }
struct Bit{
	ll c[maxn], _x[maxn], _w[maxn], tp=0;
	void update(ll x,ll w){ _x[++tp]=x, _w[tp]=w; while(x<maxn) c[x]+=w, x+=lowbit(x);}
	void update2(ll x,ll w){ while(x<maxn) c[x]+=w, x+=lowbit(x);}
	ll query(ll x){ ll res=0; while(x) res+=c[x], x-=lowbit(x); return res; }
	void clear(){ for(ll i=1;i<=tp;i++) update2(_x[i], -_w[i]); tp=0;}
	void fclear(){ tp=0; memset(c, 0, sizeof(c)); }
}bit;

inline ll maxx(ll a,ll b){ return a>b?a:b; }
inline ll minn(ll a,ll b){ return a<b?a:b; }
inline void chkmax(ll &a,ll b){ a = maxx(a, b); }
inline void chkmin(ll &a,ll b){ a = minn(a, b); }

inline void _Add(ll &a,ll b){ a+=b; if(a>=mod) a-=mod; }
inline void _Minus(ll &a,ll b){ a-=b; if(a<0) a+=mod; }
inline ll Add(ll a,ll b){ a+=b; if(a>=mod) a-=mod; return a; }
inline ll Minus(ll a,ll b){ a-=b; if(a<0) a+=mod; return a; }

inline ll qpow(ll a,ll b){
    ll ans=1, base=a;
    while(b){ if(b&1) ans=1ll*ans*base%mod; base=1ll*base*base%mod; b>>=1; }
    return ans;
}
struct Comb{
    ll fac[maxn], inv[maxn];
    Comb(){
       fac[0]=1; for(ll i=1;i<=maxn-5;i++) fac[i]=1ll*fac[i-1]*i%mod;
	   inv[maxn-5]=qpow(fac[maxn-5],mod-2); for(ll i=maxn-6;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mod;
    }
    ll C(ll a,ll b){
		if(a<0 || b<0 || a<b) return 0; return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;
	}
}comb;
ll Fac(ll x){return comb.fac[x];}ll iFac(ll x){return comb.inv[x];}ll Inv(ll x){return qpow(x, mod-2);}
/*--------------head------------------*/

ll phi[1000005], mu[1000005], vis[1000005], prim[1000005], cnt;
void init(){
	mu[1] = phi[1] = 1;
	for(ll i=2;i<=1000000;i++) {
		if(!vis[i]) {
			prim[++cnt] = i;
			phi[i] = i-1; mu[i] = -1;
		}
		for(ll j=1; j<=cnt && i*prim[j]<=1000000; j++){
			vis[i * prim[j]] = 1;
			if(i%prim[j]==0) {
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			phi[i * prim[j]] = phi[i] * (prim[j] - 1);
			mu[i * prim[j]] = -mu[i];
		}
	}
}
void clear(){  }
ll l, t, n, v[1000005];
ll vis1[1000005], vis2[1000005];
const ll N = 200000;
ll a[1000005], b[1000005];
struct _NTT_{
	ll pw[1000005],iv[1000005];
	_NTT_(){
		for(ll i=1;i<=(1ll<<19);i<<=1){
			pw[i] = qpow(3, (mod-1)/i);
			iv[i] = qpow(Inv(3), (mod-1)/i);
		}
	}
	void NTT(ll n,ll *a,ll type){
		for(ll i=0,j=0;i<n;i++){
			if(i>j) swap(a[i],a[j]);
			for(ll l=n>>1;(j^=l)<l;l>>=1);
		}
		for(ll i=2;i<=n;i<<=1){
			ll m=i>>1;
			for(ll j=0;j<n;j+=i){
				ll w=1, wn=(type==1)?pw[i]:iv[i];
				for(ll k=0;k<m;k++){
					ll z=a[j+m+k]*w%mod;
					a[j+m+k]=Minus(a[j+k], z);
					_Add(a[j+k], z);
					w=w*wn%mod;
				}
			}
		}
		if(type==-1){
			for(ll i=0;i<n;i++) a[i]=a[i]*Inv(n)%mod;
		}
	}
	void Multi(ll *a,ll *b,ll n,ll m,ll *c){
		ll N=1;
		while(N<=(n+m)) N<<=1;
		for(ll i=n+1;i<=N;i++) a[i]=0;
		for(ll i=m+1;i<=N;i++) b[i]=0;
		NTT(N, a, 1); NTT(N, b, 1);
		for(ll i=0;i<N;i++) c[i]=a[i]*b[i]%mod;
		NTT(N, c, -1);
	}
}ntt;
const ll Mod = 1e9+7;
ll ans_1;
void solve(){
	l=read(), t=read(), n=read();
	for(ll i=1;i<=n;i++) v[i]=read(), a[v[i]]++, b[v[i]]++;
	ntt.Multi(a, b, N+2, N+2, vis1);
	for(ll i=1;i<=n;i++) vis1[2*v[i]] --;
	
	memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
	for(ll i=1;i<=n;i++)  a[v[i]]++, b[200001 - v[i]]++;
	ntt.Multi(a, b, N+2, N+2, vis2);
	
	for(ll i=1;i<=N;i++) vis2[i] = vis2[i+200001];
	for(ll i=N+1;i<=2*N;i++) vis2[i] = 0;
	
	for(ll i=1;i<=2*N;i++) vis[i] = (vis1[i] || vis2[i]);
	for(ll i=1;i<=2*N;i++) {
		for(ll j=i;j<=2*N;j+=i){
			if(vis[j]){
				vis[i] = 1;
				break;
			}
		}
//		if(vis[i]) cout<<"done "<<i<<endl;
	}
	ll ans = 0; 
	for(ll i=1;i<=2*N;i++){
		for(ll j=i;j<=2*N;j+=i){
			if(!vis[j]) continue;
			ll W = t * j / (2 * l);
			// W / j <= t / 2L
			// W <= t * j / 2L
			ans = (ans + mu[i] * ((W / i) % Mod) + Mod) % Mod;
		}
	}
	printf("%lld\n", ans);
}
int main(){
    #ifdef OIcontest
        freopen(".in","r",stdin);
        freopen(".out","w",stdout);
    #endif
    #ifdef FastIO
        ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
    #endif
    init();
    ll T=1;
    while(T--) clear(), solve();
    return 0;
}
/*
Input1 Text Copied:


Answer1 Text Copied:


Input2 Text Copied:


Answer2 Text Copied:
*/
