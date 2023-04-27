#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#define fastio  		ios_base::sync_with_stdio(false) , cin.tie(NULL)
#define endl    		"\n"
#define int     		long long int
#define mod     		1000000007
#define MOD     		998244353
#define inf     		1e18 + 7
#define all(x)  		(x).begin() , (x).end()
#define rall(x) 		(x).rbegin() , (x).rend()
#define pb      		push_back
#define mp      		make_pair
#define ff      		first
#define ss      		second
#define pii     		pair<int , int>
#define pqi     		priority_queue<int>
#define sum(x)			accumulate(all(x) , 0ll)
#define print(x)		for (auto y : x) cout << y << " "; cout << endl;
#define unique(x,n)		x.resize(distance(x.begin() , unique(all(x)))) , n = a.size();

/*-------------------------------------------------------------------------*/
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (int i = 0 ; i < v.size() ; i++) is >> v[i]; return is;}
template <class T1, class T2>ostream &operator<<(ostream &os, const pair<T1, T2> &p) {return os << '{' << p.first << ", " << p.second << '}';}
template < class T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream & operator<<(ostream &os, const T &c) {os << '['; for (auto it = c.begin(); it != c.end(); ++it)os << &", "[2 * (it == c.begin())] << *it; return os << ']';}
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
	_NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  	(MACRO, ##__VA_ARGS__)
#define out(x) #x " = " << x << "; "
#ifndef ONLINE_JUDGE
#define dbg(...) cout << "Line " << __LINE__ << "-> " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#else
#define dbg(...)
#endif
/*-------------------------------------------------------------------------*/

void solve() {
	int a , b;
	cin >> a >> b;

	string s;
	cin >> s;

	int l = -1 , ans = 0;
	for (int i = 0 ; i < s.size() ; i++) {
		if (s[i] == '1') {
			ans += min(a , (i - l - 1) * b + (l == -1 ? a : 0));
			l = i;
		}
	}
	cout << ans << endl;
}

signed main() {
	fastio;
	int test_cases = 1;
	cin >> test_cases;
	for (int t = 1 ; t <= test_cases ; t++) {
		//cout << "Case #" << t << ": ";
		solve();
	}
}
