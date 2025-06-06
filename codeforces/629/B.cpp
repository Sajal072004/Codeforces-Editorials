#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <iomanip>
#include <unordered_map>
using namespace std;

#define String string
#define get getchar
#define put putchar
#define var auto
#define itn int
#define pri printf
#define sca scanf
#define put putchar
#define flo float
#define dou double
#define LL long long
#define abs(x) ((x) >= 0 ? (x) : -(x))
// 可能出现-0
#define endl '\n'
#define cu(x) ((x) * (x) * (x))
#define sq(x) ((x) * (x))
#define f_(x) fixed << setprecision(x)
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define elif else if
#define elseif else if
#define lowbit(x) ((x) & -(x))
#define inf (0x3f3f3f3f)
#define all(x) x.begin(), x.end()

LL gcd(LL a, LL b);
LL lcm(LL a, LL b);
LL exgcd(LL a, LL b, LL &x, LL &y);
LL qpow(LL x, LL n);
bool is_prime(LL x);

int M[400] = {0}, F[400] = {0}, ans = 0;
void solve()
{
    LL n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int l, r;
        cin >> l >> r;
        if (s == "M")
        {
            for (int i = l; i <= r; i++)
                ++M[i];
        }
        else
        {
            for (int i = l; i <= r; i++)
                ++F[i];
        }
    }
    for (int i = 1; i <= 366; i++)
    {
            ans = max(ans, min(M[i],F[i]));
    }
    cout << (ans << 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// 完了qwq 要31名了qwq qwq qwq qwq qwq
// 坠机了qwq qwq qwq qwq qwq qwq qwq
//
//         ||||
//         |||||                          |||                        ||          ||||
//          ||||                          ||||                       |||  || |||||||||               |||      ||||
//  ||       ||||||||||                    |||                       |||  |||||   |||||               |||      ||||
//  ||||||||||||||||||||                   |||                      ||||  |||    |||||                |||      ||||
//  ||||||||       ||||||                  |||                      |||    ||    ||||                ||||      ||||
// ||||            |||||                   |||                      |||    || ||||||                 |||       |||
// |||      |||    |                       |||                     |||     |||||||||                 |||       |||
// |||   |   |||                           |||  ||||||             |||     |||||||||                |||        |||  ||||||
// ||    ||| ||                            ||||||||||||           ||||      |||||                   |||       |||||||||||||
//      |||| || ||                    |||||||||||||||||           ||||        |||  ||||||          |||| |||||||||||||||||||
//        ||| ||||||||                |||||||||||                  |||||        |||||||||||          |||| |||||||||
//      ||||||||||||                |||||| ||                   ||| ||  |||||||||||||||||         |||||  ||  |||
//     |||||||||                           |||                  ||| || ||||||||||                ||| ||      |||
//    |||    ||                           ||||                 |||  ||  |||  |||||              |||  ||      |||
//    ||     ||||||||||||                 |||||                |    ||      |||||||            ||||  ||    ||||   |||||
//   ||||||||||||||||||||||                 ||||||                    ||      |||||||||          |||   ||    |||||||||||||
//  |||||||||||||||||||||||                ||| ||||                   ||     ||| || ||||         |     ||    |||||   |||||
//  |||||||    ||                          |||  ||||                  ||    |||  ||  ||||||            ||   ||||     |||||
//             ||                         |||    ||||                 ||   |||  |||   ||||||||         ||   ||||     ||||
//             ||                       ||||      |||||               || ||||   |||    |||||||         ||  ||||||    |||
//             ||                      ||||       |||||||            ||| ||     |||     |||           ||| ||| ||| |||||||
//             ||                    |||||         ||||||||||        |||        |||                   ||||||  |||||||||||
//             ||                   ||||            ||||||||||       |||        |||                   |||||   ||||||||||
//             ||                                     ||||||          ||        |||                   |||      ||
//             ||                                                                ||                    |       |
//             ||
//             ||
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-:-----+*#####*=-:::.=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:::--:---+*#*+--::::.=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+:::==---+=+*=-+=-:-:.-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+=-::=++++*=++==++===-:--#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+++::-****+=**+==+**+::==%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#++:::==++--=+=::-=--.:=+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:-=+=-=====--:-=:.+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:--++=+#%%%*+=+=:-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=:--++=++++=-=-:.#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-::::=++=====:...-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%= .:-::::-===-:......-#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:.::--=----:::::::-:--::=%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+-=++===+++***+**+++********#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+=+++++++++++++++***###%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%-:-====+****####%%%%%@@@@@%@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%::=+*+*#%%%%@@@@@@@@@@@@@@@@@@@@@%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@++#%%%@@@@@@@@@@@@@@@@@@@@@@@@@%%%#%%%%%#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%@@@@@@@@@@@@+%@@@@@@@%@@@@%==%%%%%*+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%@@@@@@@@@@@@%+.*#%%=+*%%@@@@#*%@@%%%#-+@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@+%%%%%@@@%%%##%%%@#*=*=+*++*%%%%@@*#@@@%%%#--@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@-+%%%@@@@#*#%%@@@@@@%%%%@@@@%%%@@%#@@@@%%%#==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--#%%@@@@@@@%*%%%*##%###%##%%#*#%%%@@@@@#*%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--#%%%@@@@@@%#%*#%%+%*%#*%#++%%%%##@@@@%**%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--##*@@@@@@@@@+%%@@@=#@%-#%+#%%@%##@@@@#+#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--##+#@@@@@@@+%#%%@%##@%*##*##%%##+@@@@*+#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--##++#@@@@@*%%%**@+*######%%*#*#%#@@@%++#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--##+++@@@@+##+*+#**%@@@%@@@%@@%@@@@@@#++#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--##+++@@@@#+#@@@%#@@@@%%#%#*%@@@@@@@@#++#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--*#+++@@@@@@@@@@@%+#@%%%###*@@@%@@@@@#**#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--*#*++@@%#@@%%%%%@%=+@%#%@@@@@@@@%%@@%**#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--*#*++@@%*#%@%%%%%@@=-##%%%@@@%@@%#@@%**#%==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--*#*++@@%**#%@%%%%%%@+:+%%@@@%%@%*#@@%***#==@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@--*#+++@@%**==%@%%%%%%@*=@%@@@@@@**#@@#***#=-@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@=-*#+++@@%**++=#@%%%%%@@@@@@%%%*#**#@@#++*#=-@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@-:+*+**@@%*=*%+=#@%%@@%%@##%+#%%##*#@@#++*#=-@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@::+++++%@@@+--===#@%%%@%#+#%#%%*+=**%@*=+*#=:@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@=:++==+@@@@@+:=::-#@%%@%*#%%%%====++%%#+++*+-%@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@+-=+==%@@@@@@%+-===#@@@@%@@@%******#%%###*+++@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@#+===+%@@@@@@@%*+-+=+%%@@@%#**#%%###%@@%%@%##@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@#%#+-+#%%%%%#%#%=**=+#%##*###%%@%%@@@@%%###**@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@*%@%*+#%###****#==***=+##*#%#%-=+=+#+#%*++===%@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@**#%@%#%%#*+**##****#**%%###%%++==++++#+==++=%@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@+=+####%%%%%%%%%%#%#%*#*+*+*+*******###+==++=%@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@+-=+++#%%%%%%%%#%%###+++++=+=+++++++#**+=-===@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@#-:-=-==+******%#***+++**++++++++++++===---:*@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@#--=========+=++=++=+++++++==+====-------:*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=-++**==----------==+*++=------------:-#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=---:....              .   ....:::-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##*++++++##+++++++++#%*+++***#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}
LL lcm(LL a, LL b)
{
    return a * b / gcd(a, b);
}
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
} // ax + by = gcd(a,b);返回值为gcd(a,b)

LL qpow(LL x, LL n)
{
    LL ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}
bool is_prime(LL x)
{
    if (x < 2)
        return false;
    for (LL i = 2; i <= x / i; i++)
        if (x % i == 0)
            return false;
    return true;
}
					 											  				 	  		 	