#line 1 "/home/maspy/compro/library/my_template.hpp"
#if defined(LOCAL)
#include <my_template_compiled.hpp>
#else

// https://codeforces.com/blog/entry/96344
#pragma GCC optimize("Ofast,unroll-loops")
// いまの CF だとこれ入れると動かない？
// #pragma GCC target("avx2,popcnt")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using f128 = __float128;

template <class T>
constexpr T infty = 0;
template <>
constexpr int infty<int> = 1'000'000'000;
template <>
constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;
template <>
constexpr u32 infty<u32> = infty<int>;
template <>
constexpr u64 infty<u64> = infty<ll>;
template <>
constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;
template <>
constexpr double infty<double> = infty<ll>;
template <>
constexpr long double infty<long double> = infty<ll>;

using pi = pair<ll, ll>;
using vi = vector<ll>;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

// https://trap.jp/post/1224/
#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)
#define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)
#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)
#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))
#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0); --i)
#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)
#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)

#define FOR_subset(t, s) \
  for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }
int popcnt_mod_2(int x) { return __builtin_parity(x); }
int popcnt_mod_2(u32 x) { return __builtin_parity(x); }
int popcnt_mod_2(ll x) { return __builtin_parityll(x); }
int popcnt_mod_2(u64 x) { return __builtin_parityll(x); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)
int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }
int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
int topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }
// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)
int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }
int lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }

template <typename T>
T floor(T a, T b) {
  return a / b - (a % b && (a ^ b) < 0);
}
template <typename T>
T ceil(T x, T y) {
  return floor(x + y - 1, y);
}
template <typename T>
T bmod(T x, T y) {
  return x - y * floor(x, y);
}
template <typename T>
pair<T, T> divmod(T x, T y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

template <typename T, typename U>
T SUM(const vector<U> &A) {
  T sm = 0;
  for (auto &&a: A) sm += a;
  return sm;
}

#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) \
  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()

template <typename T>
T POP(deque<T> &que) {
  T a = que.front();
  que.pop_front();
  return a;
}
template <typename T>
T POP(pq<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(pqg<T> &que) {
  T a = que.top();
  que.pop();
  return a;
}
template <typename T>
T POP(vc<T> &que) {
  T a = que.back();
  que.pop_back();
  return a;
}

template <typename F>
ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {
  if (check_ok) assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    (check(x) ? ok : ng) = x;
  }
  return ok;
}
template <typename F>
double binary_search_real(F check, double ok, double ng, int iter = 100) {
  FOR(iter) {
    double x = (ok + ng) / 2;
    (check(x) ? ok : ng) = x;
  }
  return (ok + ng) / 2;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

// ? は -1
vc<int> s_to_vi(const string &S, char first_char) {
  vc<int> A(S.size());
  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }
  return A;
}

template <typename T, typename U>
vector<T> cumsum(vector<U> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

// stable sort
template <typename T>
vector<int> argsort(const vector<T> &A) {
  vector<int> ids(len(A));
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });
  return ids;
}

// A[I[0]], A[I[1]], ...
template <typename T>
vc<T> rearrange(const vc<T> &A, const vc<int> &I) {
  vc<T> B(len(I));
  FOR(i, len(I)) B[i] = A[I[i]];
  return B;
}
#endif
#line 1 "/home/maspy/compro/library/other/io2.hpp"
#define INT(...)   \
  int __VA_ARGS__; \
  IN(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  IN(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  IN(__VA_ARGS__)
#define CHR(...)    \
  char __VA_ARGS__; \
  IN(__VA_ARGS__)
#define DBL(...)           \
  long double __VA_ARGS__; \
  IN(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void read(int &a) { cin >> a; }
void read(long long &a) { cin >> a; }
void read(char &a) { cin >> a; }
void read(double &a) { cin >> a; }
void read(long double &a) { cin >> a; }
void read(string &a) { cin >> a; }
template <class T, class S>
void read(pair<T, S> &p) {
  read(p.first), read(p.second);
}
template <class T>
void read(vector<T> &a) {
  for (auto &i: a) read(i);
}
template <class T>
void read(T &a) {
  cin >> a;
}
void IN() {}
template <class Head, class... Tail>
void IN(Head &head, Tail &... tail) {
  read(head);
  IN(tail...);
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &A) {
  os << A.fi << " " << A.se;
  return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &A) {
  for (size_t i = 0; i < A.size(); i++) {
    if (i) os << " ";
    os << A[i];
  }
  return os;
}

void print() {
  cout << "\n";
  cout.flush();
}

template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  cout << head;
  if (sizeof...(Tail)) cout << " ";
  print(forward<Tail>(tail)...);
}

#define SHOW(x) print(#x, "=", (x))

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 3 "main.cpp"

#line 2 "/home/maspy/compro/library/random/base.hpp"

u64 RNG_64() {
  static uint64_t x_
      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(
                     chrono::high_resolution_clock::now().time_since_epoch())
                     .count())
        * 10150724397891781847ULL;
  x_ ^= x_ << 7;
  return x_ ^= x_ >> 9;
}

u64 RNG(u64 lim) { return RNG_64() % lim; }

ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }
#line 2 "/home/maspy/compro/library/geo/base.hpp"
template <typename T>
struct Point {
  T x, y;

  Point() : x(0), y(0) {}

  template <typename A, typename B>
  Point(A x, B y) : x(x), y(y) {}

  template <typename A, typename B>
  Point(pair<A, B> p) : x(p.fi), y(p.se) {}

  Point operator+(Point p) const { return {x + p.x, y + p.y}; }
  Point operator-(Point p) const { return {x - p.x, y - p.y}; }
  bool operator==(Point p) const { return x == p.x && y == p.y; }
  bool operator!=(Point p) const { return x != p.x || y != p.y; }
  Point operator-() const { return {-x, -y}; }
  Point operator*(T t) const { return {x * t, y * t}; }
  Point operator/(T t) const { return {x / t, y / t}; }

  bool operator<(Point p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  T dot(Point other) { return x * other.x + y * other.y; }
  T det(Point other) { return x * other.y - y * other.x; }

  double norm() { return sqrtl(x * x + y * y); }
  double angle() { return atan2(y, x); }

  Point rotate(double theta) {
    static_assert(!is_integral<T>::value);
    double c = cos(theta), s = sin(theta);
    return Point{c * x - s * y, s * x + c * y};
  }
};

#ifdef FASTIO
template <typename T>
void rd(Point<T>& p) {
  fastio::rd(p.x), fastio::rd(p.y);
}
template <typename T>
void wt(Point<T>& p) {
  fastio::wt(p.x);
  fastio::wt(' ');
  fastio::wt(p.y);
}
#endif

// A -> B -> C と進むときに、左に曲がるならば +1、右に曲がるならば -1
template <typename T>
int ccw(Point<T> A, Point<T> B, Point<T> C) {
  T x = (B - A).det(C - A);
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}

template <typename REAL, typename T>
REAL dist(Point<T> A, Point<T> B) {
  A = A - B;
  T p = A.dot(A);
  return sqrt(REAL(p));
}

// ax+by+c
template <typename T>
struct Line {
  T a, b, c;

  Line(T a, T b, T c) : a(a), b(b), c(c) {}
  Line(Point<T> A, Point<T> B) {
    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;
  }
  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}

  template <typename U>
  U eval(Point<U> P) {
    return a * P.x + b * P.y + c;
  }

  template <typename U>
  T eval(U x, U y) {
    return a * x + b * y + c;
  }

  // 同じ直線が同じ a,b,c で表現されるようにする
  void normalize() {
    static_assert(is_same_v<T, int> || is_same_v<T, long long>);
    T g = gcd(gcd(abs(a), abs(b)), abs(c));
    a /= g, b /= g, c /= g;
    if (b < 0) { a = -a, b = -b, c = -c; }
    if (b == 0 && a < 0) { a = -a, b = -b, c = -c; }
  }

  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }
  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }
};

template <typename T>
struct Segment {
  Point<T> A, B;

  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}
  Segment(T x1, T y1, T x2, T y2)
      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}

  bool contain(Point<T> C) {
    static_assert(is_integral<T>::value);
    T det = (C - A).det(B - A);
    if (det != 0) return 0;
    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;
  }

  Line<T> to_Line() { return Line(A, B); }
};

template <typename REAL>
struct Circle {
  Point<REAL> O;
  REAL r;
  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}
  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}
  template <typename T>
  bool contain(Point<T> p) {
    REAL dx = p.x - O.x, dy = p.y - O.y;
    return dx * dx + dy * dy <= r * r;
  }
};

template <typename T>
struct Polygon {
  vc<Point<T>> points;
  T a;

  template <typename A, typename B>
  Polygon(vc<pair<A, B>> pairs) {
    for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));
    build();
  }
  Polygon(vc<Point<T>> points) : points(points) { build(); }

  int size() { return len(points); }

  template <typename REAL>
  REAL area() {
    return a * 0.5;
  }

  template <enable_if_t<is_integral<T>::value, int> = 0>
  T area_2() {
    return a;
  }

  bool is_convex() {
    FOR(j, len(points)) {
      int i = (j == 0 ? len(points) - 1 : j - 1);
      int k = (j == len(points) - 1 ? 0 : j + 1);
      if ((points[j] - points[i]).det(points[k] - points[j]) < 0) return false;
    }
    return true;
  }

private:
  void build() {
    a = 0;
    FOR(i, len(points)) {
      int j = (i + 1 == len(points) ? 0 : i + 1);
      a += points[i].det(points[j]);
    }
    if (a < 0) {
      a = -a;
      reverse(all(points));
    }
  }
};
#line 6 "main.cpp"

using Re = double;
using P = Point<Re>;

Re random_real() {
  Re x = RNG(0, 1e18);
  return x / (1e18);
}

void solve() {
  LL(N);

#if defined(LOCAL)
  vc<P> god;
  god.eb(P{1, 3});
  god.eb(P{2.5, 0.5});
#endif

  auto ask = [&](Re a, Re b) -> vc<P> {
    print("?", a, b, 0.0);
    vc<P> res(N);
    FOR(i, N) {
      DBL(a, b);
      res[i] = {a, b};
    }
    return res;
  };

  vc<Re> X, Y;
  {
    vc<P> p = ask(0, 1);
    // y=0 (*,0)
    FOR(i, N) X.eb(p[i].x);
  }
  {
    vc<P> p = ask(1, 0);
    FOR(i, N) Y.eb(p[i].y);
  }

  while (1) {
    Re a = random_real(), b = random_real();
    a = 2 * a - 1, b = 2 * b - 1;
    if (abs(a) + abs(b) <= 0.2) continue;
    vc<Re> Z;
    vc<pair<int, int>> idx;
    FOR(i, N) FOR(j, N) {
      Re x = X[i], y = Y[j];
      Z.eb(b * x - a * y);
      idx.eb(i, j);
    }
    auto I = argsort(Z);
    Z = rearrange(Z, I);
    idx = rearrange(idx, I);
    bool ok = 1;
    Re eps = 5e-4;
    FOR(i, N * N - 1) {
      if (Z[i + 1] <= Z[i] + eps) ok = 0;
    }
    if (!ok) continue;
    vc<P> dat = ask(a, b);
    vc<pair<Re, Re>> ANS;
    FOR(i, N) {
      P p = dat[i];
      Re t = b * p.x - a * p.y;
      vc<Re> diff(N * N);
      FOR(j, N * N) diff[j] = abs(t - Z[j]);
      int k = min_element(all(diff)) - diff.begin();
      auto [c, d] = idx[k];
      ANS.eb(X[c], Y[d]);
    }
    print("!", ANS);
    return;
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
