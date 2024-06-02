#include <bits/stdc++.h>
using namespace std;

void Print_int_vect(vector<int> &vect)
{
    for (int el : vect)
    {
        cout << el << " ";
    }
    cout << endl;
}

void Print_numb_vect(vector<int> &vect)
{
    for (int el : vect)
    {
        cout << el;
    }
    cout << endl;
}

void Print_long_vect(vector<long long> &vect)
{
    for (long long el : vect)
    {
        cout << el << " ";
    }
    cout << endl;
}

void Print_bool_vect(vector<bool> &vect)
{
    for (int el : vect)
    {
        cout << el << " ";
    }
    cout << endl;
}

void Print_bool_2vect(vector<vector<bool>> &vect)
{
    for (vector<bool> el : vect)
    {
        Print_bool_vect(el);
    }
}

void Print_char_vect(vector<char> &vect)
{
    for (auto el : vect)
    {
        cout << el;
    }
    cout << endl;
}

void Print_int_stack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void Print_long_stack(stack<long int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void Print_string_stack(stack<string> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

vector<int> CIN_vector(int n)
{
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    return v;
}

void combinations_rec(int n, int k, int index, vector<int> &comb)
{
    if (k == 0)
    {
        Print_int_vect(comb);
        return;
    }
    for (int i = index + 1; i <= n - k + 1; i++)
    {
        comb.push_back(i - 1);
        combinations_rec(n, k - 1, i, comb);
        comb.pop_back();
    }
}

void combinations(int n, int k)
{
    vector<int> comb;
    combinations_rec(n, k, 0, comb);
}
long long bin_gcd(long long a, long long b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    if (a == 0 || b == 0)
        return a + b;
    if (a == 1 || b == 1)
        return 1;
    if (a == b)
        return a;
    if ((a & 1) == 0 and (b & 1) == 0)
        return (bin_gcd(a >> 1, b >> 1) << 1);
    if ((a & 1) == 0)
        return bin_gcd(a >> 1, b);
    if ((b & 1) == 0)
        return bin_gcd(b >> 1, a);
    if (a > b)
        return bin_gcd((a - b) >> 1, b);
    return bin_gcd((b - a) >> 1, a);
}

int bin_vect(int index)
{
    vector<int> answer;
    while (index)
    {
        answer.push_back(index % 2);
        index /= 2;
    }
    reverse(answer.begin(), answer.end());
    int a = 0;
    for (int el : answer)
    {
        a = a * 10 + el;
    }

    return a;
}
vector<int> Factorization(int n)
{
    int d = 2;
    vector<int> answer;
    do
    {
        while (n % d == 0)
        {
            answer.push_back(d);
            n /= d;
        }
        if (d * 1LL * d > n and n != 1)
        {
            answer.push_back(n);
            break;
        }
        d++;
    } while (n != 1);
    return answer;
}

struct Factor
{
    int prime;
    int power;
};

vector<Factor> factorization(int n)
{
    if (n == 1)
    {
        vector<Factor> F(1);
        Factor f = Factor();
        f.power = 0;
        f.prime = 1;
        F[0] = f;
        return F;
    }
    int d = 2;
    vector<Factor> F;
    while (n != 1)
    {
        if (n % d == 0)
        {
            Factor factor = Factor();
            factor.prime = d;
            while (n % d == 0)
            {
                factor.power++;
                n /= d;
            }
            F.push_back(factor);
        }
        if (d * 1LL * d > n and n != 1)
        {
            Factor factor = Factor();
            factor.prime = n;
            factor.power = 1;
            F.push_back(factor);
            break;
        }
        d++;
    }
    return F;
}

long long v_gcd(vector<long long> v)
{
    long long answer = 0;
    for (int el : v)
    {
        answer = bin_gcd(answer, el);
    }
    return answer;
}

struct Node
{
    int value = -1;
};

int max_subarray(vector<int> v, int l)
{
    int b = 0, e = 0, max_b, max_e;
    long long c_sum = 0, max_sum = 0;
    for (e = 0; e < v.size(); e++)
    {
        if (e >= l)
        {
            c_sum -= v[b];
            b++;
        }
        c_sum += v[e];
        if (c_sum > max_sum)
        {
            max_sum = c_sum;
            max_b = b;
            max_e = e;
        }
    }
    // vector<int> ans (l);
    // fill(v.begin() + max_b, v.begin() + max_e, ans.begin());
    return max_b;
}

long long max_gcd;

int v_product(vector<int> v)
{
    long long ans = 1;
    for (int el : v)
    {
        if (el != 0)
            ans *= el;
    }
    return ans;
}

int get_min_dist(vector<int> v)
{
    int m = 1000000000, ind;
    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i + 1] - v[i - 1] < m)
        {
            m = v[i + 1] - v[i - 1];
            ind = i;
        }
    }
    return ind;
}

bool is_prime(long long n)
{
    long long factor = 2;
    while (factor * factor <= n)
    {
        if (n % factor++ == 0)
        {
            return false;
        }
    }
    return true;
}

void rec(long long a, long long b)
{
    // cout << a << ' ' << b << endl;
    if (a == 0 || b == 0)
    {
        cout << a << ' ' << b;
    }
    else if (a >= 2 * b)
    {
        long long dd = 2 * b;
        long long new_val = a - (a / dd) * dd;
        rec(new_val, b);
    }
    else if (b >= 2 * a)
    {
        long long dd = 2 * a;
        long long new_val = b - (b / dd) * dd;
        rec(a, new_val);
    }
    else
    {
        cout << a << ' ' << b;
    }
}

int sum_numb(int n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

vector<int> next_sum_ten(vector<int> v)
{
    int ind_decr = v.size() - 1;
    while (ind_decr and v[ind_decr] == 0)
    {
        ind_decr--;
    }
    int ind_incr = ind_decr - 1;
    v[ind_incr]++;
    if (v[0] == 10)
    {
        vector<int> res_v(v.size() + 1, 0);
        res_v[0] = 1;
        res_v[v.size()] = 9;
        return res_v;
    }
    v[ind_decr]--;
    reverse(v.begin() + ind_decr, v.end());
    return v;
}

int euklid_dist(int x, int y)
{
    int dist = sqrt(x * x + y * y);
    return dist;
}

void task()
{
    int n, k;
    cin >> n >> k;
    int need_2 = k, need_5 = k;
    vector<Factor> f_v = factorization(n);
    for (Factor f : f_v)
    {
        if (f.prime == 2)
        {
            need_2 -= f.power;
        }
        else if (f.prime == 5)
        {
            need_5 -= f.power;
        }
    }

    long long new_n = n * pow(5, max(0, need_5)) * pow(2, max(0, need_2));
    cout << new_n;
}
// 12
// 66 6 3 33 22 3 1 1 2 11 11 33

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;

    // cin >> t;

    for (int i = 0; i < t; i++)
    {
        task();
    }
}