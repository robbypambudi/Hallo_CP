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

void solve()
{
}
int main()
{
    fast_cin();
    int t, k;
    ll coutn = 0;
    cin >> t >> k;
    forn(t)
    {
        ll value;
        cin >> value;
        if (value % k == 0)
        {
            coutn += 1;
        }
    }
    cout << coutn;
    return 0;
}