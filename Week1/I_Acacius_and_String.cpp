#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;

// KKKKKKKKK    KKKKKKK               AAA               LLLLLLLLLLL             IIIIIIIIII        66666666           66666666           66666666
// K:::::::K    K:::::K              A:::A              L:::::::::L             I::::::::I       6::::::6           6::::::6           6::::::6
// K:::::::K    K:::::K             A:::::A             L:::::::::L             I::::::::I      6::::::6           6::::::6           6::::::6
// K:::::::K   K::::::K            A:::::::A            LL:::::::LL             II::::::II     6::::::6           6::::::6           6::::::6
// KK::::::K  K:::::KKK           A:::::::::A             L:::::L                 I::::I      6::::::6           6::::::6           6::::::6
//   K:::::K K:::::K             A:::::A:::::A            L:::::L                 I::::I     6::::::6           6::::::6           6::::::6
//   K::::::K:::::K             A:::::A A:::::A           L:::::L                 I::::I    6::::::6           6::::::6           6::::::6
//   K:::::::::::K             A:::::A   A:::::A          L:::::L                 I::::I   6::::::::66666     6::::::::66666     6::::::::66666
//   K:::::::::::K            A:::::A     A:::::A         L:::::L                 I::::I  6::::::::::::::66  6::::::::::::::66  6::::::::::::::66
//   K::::::K:::::K          A:::::AAAAAAAAA:::::A        L:::::L                 I::::I  6::::::66666:::::6 6::::::66666:::::6 6::::::66666:::::6
//   K:::::K K:::::K        A:::::::::::::::::::::A       L:::::L                 I::::I  6:::::6     6:::::66:::::6     6:::::66:::::6     6:::::6
// KK::::::K  K:::::KKK    A:::::AAAAAAAAAAAAA:::::A      L:::::L         LLLLLL  I::::I  6:::::6     6:::::66:::::6     6:::::66:::::6     6:::::6
// K:::::::K   K::::::K   A:::::A             A:::::A   LL:::::::LLLLLLLLL:::::LII::::::II6::::::66666::::::66::::::66666::::::66::::::66666::::::6
// K:::::::K    K:::::K  A:::::A               A:::::A  L::::::::::::::::::::::LI::::::::I 66:::::::::::::66  66:::::::::::::66  66:::::::::::::66
// K:::::::K    K:::::K A:::::A                 A:::::A L::::::::::::::::::::::LI::::::::I   66:::::::::66      66:::::::::66      66:::::::::66
// KKKKKKKKK    KKKKKKKAAAAAAA                   AAAAAAALLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII     666666666          666666666          666666666

#define MOD 1000000007
#define PI 3.141592653589793238462
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*########################################### DEBUG ###############################################################################################*/
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(long long t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

/*###############################################################################################################################################*/
int check(string &a, string &b)
{
    int count = 0;
    int n = a.length(), m = b.length();
    for (int i = 0; i < n - m + 1; ++i)
    {
        string temp;
        for (int j = i; j < i + 7; ++j)
        {
            temp.push_back(a[j]);
        }
        if (temp == b)
        {
            count++;
        }
    }
    return count;
}
bool exists(string &alpha)
{
    if ((alpha[0] == 'a' || alpha[0] == '?') && (alpha[1] == 'b' || alpha[1] == '?') && (alpha[2] == 'a' || alpha[2] == '?') && (alpha[3] == 'c' || alpha[3] == '?') &&
        (alpha[4] == 'a' || alpha[4] == '?') && (alpha[5] == 'b' || alpha[5] == '?') && (alpha[6] == 'a' || alpha[6] == '?'))
    {
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string alpha;
        cin >> alpha;
        bool answer = false;
        string target = "abacaba";
        int key = check(alpha, target);
        if (check(alpha, target) == 0)
        {
            int n = alpha.length();
            int m = target.length();
            for (int i = 0; i < (n - m + 1); ++i)
            {
                string temp;
                for (int j = i; j < i + 7; ++j)
                {
                    temp.push_back(alpha[j]);
                }
                if (exists(temp) == true)
                {
                    string temp1;
                    for (int k = 0; k < i; ++k)
                    {
                        if (alpha[k] == '?')
                        {
                            temp1.push_back('z');
                        }
                        else
                        {
                            temp1.push_back(alpha[k]);
                        }
                    }
                    temp1 = temp1 + target;
                    for (int k = i + 7; k < n; ++k)
                    {
                        if (alpha[k] == '?')
                        {
                            temp1.push_back('z');
                        }
                        else
                        {
                            temp1.push_back(alpha[k]);
                        }
                    }
                    if (check(temp1, target) == 1)
                    {
                        cout << "Yes\n";
                        cout << temp1 << "\n";
                        answer = true;
                        break;
                    }
                }
            }
            if (answer == false)
            {
                cout << "No\n";
            }
        }
        else if (check(alpha, target) == 1)
        {
            for (int i = 0; i < alpha.length(); ++i)
            {
                if (alpha[i] == '?')
                {
                    alpha[i] = 'z';
                }
            }
            cout << "Yes\n";
            cout << alpha << "\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}