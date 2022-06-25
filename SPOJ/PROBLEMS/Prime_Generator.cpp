#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define forn(e) for (int i = 0; i < e; i++)
#define ll long long
#define llu long long unsigned
#define vi vector<int>
#define vll vector<long long>

vector<char> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<char> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

void solve()
{
    vector<char> primes;
    ll a, b;
    cin >> a >> b;
    primes = segmentedSieve(a, b);

    vector<char>::iterator it = primes.begin();
    ll temp = a;
    while (it != primes.end())
    {
        if (*it != false)
        {
            cout << a << "\n";
        }
        a++;
        it++;
    }
    cout << "\n";
}
int main()
{
    fast_cin();
    int t;
    cin >> t;
    forn(t)
    {
        solve();
    }
    return 0;
}