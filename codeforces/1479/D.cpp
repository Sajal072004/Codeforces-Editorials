//Never compromise. Not even in the face of Armageddon.

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

//pragmas
#pragma GCC optimize("03")
// #pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("01, 02, 03, 0fast, unroll-loops")              //Retard mode
//#pragma GCC optimize("Ofast,unroll-loops,omit-frame-pointer,inline")     //Optimization flags
//#pragma GCC option("arch=native,tune=native,no-zero-upper")              //Enable AVX

//types
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define TYPE long long
#define ppair pair<TYPE, TYPE>
#define vecvec(a, i, j, x) vector<vector<TYPE>> a (i, vector<TYPE> (j, x))
#define vecvecvec(a, i, j, k, x) vector<vector<vector<TYPE>>> dp (i + 1, vector<vector<TYPE>>(j + 1, vector<TYPE>(k + 1, x)))

using namespace std;
using namespace __gnu_pbds;

//random stuff
#define all(a) a.begin(),a.end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define sz(x) (long long int)x.size()
#define F first
#define S second
#define sp " " 
const ll inf = 0x3f3f3f3f, INF = 1e18;
const int MOD = 1e9 + 7;
const ll BIG_MOD = 489133282872437279; //use to decrease hash collision probability

typedef tree<long long int, null_type, less<long long int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;             //for multiset, use less_equal and erase x in multiset a -> a.erase(a.find_by_order(a.order_of_key(x)))
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define safe_map unordered_map<long long, int, custom_hash>
#define hashmap gp_hash_table<int, int, custom_hash>


//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define reach cerr<<"reached"<<endl
#else
#define debug(x...)
#define reach 
#endif


/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m = MOD) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
void precision(int a) {cout << setprecision(a) << fixed;}
ll ceil_div(ll x, ll y){return (x + y - 1) / y;}
unsigned long long power(unsigned long long x,ll y, ll p){unsigned long long res = 1;x = x % p; while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;}
unsigned long long modInverse(unsigned long long n,int p){return power(n, p - 2, p);}
ll nCr(ll n,ll r, ll p){if (n < r)return 0;if (r == 0)return 1;unsigned long long fac[n + 1];fac[0] = 1;for (int i = 1; i <= n; i++)fac[i] = (fac[i - 1] * i) % p;return (fac[n] * modInverse(fac[r], p) % p* modInverse(fac[n - r], p) % p)% p;}
ll accumulate(const vector<long long int> &nums){ll sum = 0; for(auto x : nums) sum += x; return sum;}
ll tmax(ll a, ll b, ll c = 0, ll d = -INF, ll e = -INF, ll f = -INF){return max(a, max(b, max(c, max(d, max(e, f)))));}
int log2_floor(unsigned long long i) {return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;}
string bin(ll n){return bitset<32>(n).to_string();}
/*--------------------------------------------------------------------------------------------------------------------------*/

//#define int int64_t

const int MAXN = 3e5+5;

int n, q;
int a[MAXN], tin[MAXN], tout[MAXN];
vector<int> adj[MAXN];

struct LCA
{
    int n, L, timer;

    // vector<int> adj[MAXN];       //just keep this outside

    vector<vector<int>> up;         //up[v][i] stores (2^i) ancestor of v

    // w[] is basically "cost" for a node

    void init(int x)
    {
        n = x;
        L = ceil(log2(n));
        up.assign(n + 1, vector<int>(L + 1));
    }

    void dfs(int v, int p)
    {
        tin[v] = ++timer;
 
        up[v][0] = p;
 
        for (int i = 1; i <= L; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
 
        for (int u : adj[v])
            if (u != p)
                dfs(u, v);

        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    void preprocess(int root) 
    {
        timer = 0;
        dfs(root, root);
    }

    int lca(int u, int v)           //lca of u and v
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
 
        for (int i = L; i >= 0; --i) 
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
 
        return up[u][0];
    }
}lca;

const int R = 2000, R2 = 800;
bool cmp1(const vector<int>&x, const vector<int>&y)       //{l, r are first two elements}
{
    return make_pair(x[0]/R, x[1]) < make_pair(y[0]/R, y[1]);
}
bool cmp2(const array<int, 6>&x, const array<int, 6>&y)
{
	if(x[0]/R==y[0]/R)
	{
		if((x[0]/R)&1)
			return x[1]>y[1];
		else
			return y[1]>x[1];
	}
	return x[0]<y[0];
}

bool odd[MAXN];
int block[2*MAXN], col[2*MAXN];

struct Mo
{
    int n, q;

    vector<int> ans;
    vector<array<int, 6>> query;          //{u, v, l, r, lca, index}

    void init(int x, int *original)      //one indexed
    {
        n = x;

        for(int i = 1; i <= n; i ++)    col[tin[i]] = col[tout[i]] = original[i];
    }

    void add_query(array<int, 6> qu)    {query.pb(qu), q = query.size();}

    int bl(int i)   {return (i + R2 - 1)/R2;}

    // Data Structure Operations
    void toggle(int i)
    {
        block[bl(i)] += !odd[i] - odd[i];

        odd[i] = !odd[i];
    }
    int get(int l, int r)
    {
        int B1 = bl(l), B2 = bl(r);

        if(B1 == B2)
        {
            for(int i = l; i <= r; ++ i)
                if(odd[i])
                    return i;
        }
        else
        {
            for(int i = l; i <= B1 * R2; ++ i)
                if(odd[i])
                    return i;
            
            for(int B = B1 + 1; B < B2; ++ B)
                if(block[B])
                    for(int i = (B - 1) * R2 + 1; i <= B * R2; ++ i)
                        if(odd[i])
                            return i;
            
            for(int i = (B2 - 1) * R2 + 1; i <= r; ++ i)
                if(odd[i])
                    return i;
        }
        return -1;
    }

    void process()
    {
        // sort
        sort(all(query), cmp2);      //define comparator outside

        // go through
        int q = query.size();
        ans.resize(q + 1);

        int L = 1, R = 0;
        for(int i = 0; i < q; i ++)
        {
            int l = query[i][0], r = query[i][1];       //of queries

            while (L > l)
            {
                L --;
                toggle(col[L]);
            }
            while (R < r)
            {
                R ++;
                toggle(col[R]);
            }
            while(L < l)
            {
                toggle(col[L]);
                L ++;
            }
            while (R > r)
            {
                toggle(col[R]);
                R --;
            }

            if(query[i][4] != 0)
                toggle(query[i][4]);

            int idx = query[i][5];

            ans[idx] = get(query[i][2], query[i][3]);

            if(query[i][4] != 0)
                toggle(query[i][4]);
        }
    }
}mo;

//code starts
int32_t main()
{
    fastio();
    cin >> n >> q;
    for(int i = 1; i <= n; i ++)    cin >> a[i];

    for(int i = 1, u, v; i < n; i ++)   cin >> u >> v, adj[u].pb(v), adj[v].pb(u);

    lca.init(n);
    lca.preprocess(1);

    mo.init(n, a);

    for(int i = 1, u, v, l, r; i <= q; i ++)
    {
        cin >> u >> v >> l >> r;
        if(tin[u] > tin[v]) swap(u, v);

        if(lca.is_ancestor(u, v))
            mo.add_query({tin[u], tin[v], l, r, 0, i});
        else
            mo.add_query({tout[u], tin[v], l, r, a[lca.lca(u, v)], i});
    }

    mo.process();
    for(int i = 1; i <= q; i ++)    cout << mo.ans[i] << endl;
}





// There is an idea of a Patrick Bateman. Some kind of abstraction.
// But there is no real me. Only an entity. Something illusory. 
// And though I can hide my cold gaze, and you can shake my hand and
// feel flesh gripping yours, and maybe you can even sense our lifestyles
// are probably comparable, I simply am not there.