
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
int64_t inf = 1e18;
int64_t mod = 998244353;//998244353
using namespace std;
#define Yes cout <<"Yes\n";
#define No cout <<"No\n";
#define YES cout <<"YES\n";
#define NO cout <<"NO\n";
#define YESR {YES return;}
#define NoR {No return;}
#define YesR {Yes return;}
#define NOR {NO return;}
long double eps = 1e-10;
#define int long long
#define double long double
#define MP make_pair
//using i128 = __int128_t;
#define __ << ' ' <<
#define endl "\n"
#define unordered_map __fast_unordered_map
template<class Key, class Value, class Hash = std::hash<Key>>
using unordered_map = __gnu_pbds::gp_hash_table<Key, Value, Hash>;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) {if (b == 0) return a;return gcd(b, a % b);}
template<typename typC, typename typD> istream& operator>>(istream& cin, pair<typC, typD>& a) { return cin >> a.first >> a.second; }
template<typename typC> istream& operator>>(istream& cin, vector<typC>& a) { for (auto& x : a) cin >> x; return cin; }
template<typename typC, typename typD> ostream& operator<<(ostream& cout, const pair<typC, typD>& a) { return cout << a.first << ' ' << a.second; }
template<typename typC, typename typD> ostream& operator<<(ostream& cout, const vector<pair<typC, typD>>& a) { for (auto& x : a) cout << x << '\n'; return cout; }
template<typename typC> ostream& operator<<(ostream& cout, const vector<typC>& a) { int n = a.size(); if (!n) return cout; cout << a[0]; for (int i = 1; i < n; i++) cout << ' ' << a[i]; return cout; }
template<typename typC> istream& operator>>(istream& cin, const vector<vector<typC>>& a) { for (int i = 0; i < a.size(); ++i)for (int j = 0; j < a[0].size(); ++j)cin >> a[i][j]; return cin; }
template<typename typC> ostream& operator<<(ostream& cout, const vector<vector<typC>>& a) { int n = a.size(); if (!n) return cout; for (int i = 0; i < a.size(); ++i) { for (int j = 0; j < a[0].size(); ++j) { 
cout << a[i][j] << ' '; }if (i != n - 1) cout << endl; }return cout; }
template <typename T>
void dbg(vector<T> v) { for (const auto& el : v) cerr << el << ' '; cerr << endl; }
template <typename T1, typename T2>
void dbg(pair<T1, T2> p) { cerr << p.first << ' ' << p.second << endl; }
template <typename T1, typename T2>
void dbg(vector<pair<T1, T2>> v) { for (const auto& el : v) cerr << el.first << ' ' << el.second << endl; cerr << endl; }
template <typename T>
void dbg(stack<T> q) { while (q.size()) { cerr << q.top() << ' '; q.pop(); }cerr << endl; }
template <typename T>
void dbg(priority_queue<T> q) { while (q.size()) { cerr << q.top() << ' '; q.pop(); }cerr << endl; }
template <typename T>
void dbg(vector<vector<T>> v) { for (const auto& x : v) { for (const auto& y : x) { cerr << y << ' '; }cerr << endl; }cerr << endl; }
template <typename T>
void dbg(set<T> v) { for (const auto& el : v) cerr << el << ' '; cerr << endl; }
template <typename T>
void dbg(multiset<T> v) { for (const auto& el : v) cerr << el << ' '; cerr << endl; }
template <typename T>
void dbg(deque<T> q) { while (q.size()) { cerr << q.front() << ' '; q.pop_front(); }cerr << endl; }
template <typename T1, typename T2>
void dbg(map<T1, T2> hash) { for (const auto& el : hash) { cerr << el.first << " : " << el.second << endl; }cerr << endl; }

template<typename T> constexpr bool cmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template<typename T> constexpr bool cmin(T &a, const T &b) { return b < a ? a = b, true : false; }
int POW(int a, int b, int m) { a %= m; int r = 1; while (b > 0) { if (b & 1) { r = (r * a) % m; } a = (a * a) % m; b /= 2; }return r; }
void bin(int x) {string r;while (x) {r = to_string(x % 2) + r;x /= 2;}r = string(63 - r.size(), '0') + r; cerr << r << endl;}
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1};
inline int mul(int a, int b) {a %= mod;b %= mod;return a * b % mod;}
inline void Add(int& res, int a){ res = (res + a + mod) % mod;}
inline int sub(int res, int a){ res = (res - a + mod) % mod;return res;}
int Div(int res, int d){return (res % mod) * POW(d, mod-2, mod) % mod;}

#define zero {cout << "0\n"; return;}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), mn(k);
	cin >> a >> mn;
	if(a[0] < mn[0] || *min_element(all(a)) < mn[0]) zero
	reverse(all(a));
	reverse(all(mn));
	int m = a[0], i = 0, res = 1, done = 1;
	while(i < n && m > mn[0]){
		++i;
		cmin(m, a[i]);				
	}	
	if(i == n || m != mn[0]) zero
	

	for(;i < n;){		
		if(done == k){
			if(*min_element(a.begin() + i, a.end()) < mn.back()) zero
			break;
		}
		int j = i, f = 1;
		while(j < n && m != mn[done]){
			++j;
			cmin(m, a[j]);
			if(f && m < mn[done-1]){
				f = 0;
				res = mul(res, j - i);
			}
		}
		//cerr << m __ mn[done] << endl;
		if(m != mn[done] || j >= n) zero
		done++;
		i = j;
	}
	
	
	cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);// comment in interactive
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

}

