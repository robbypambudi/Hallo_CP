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
    int L;
    cin >> L;

    vi v;
    while (L != 42)
    {
        v.pb(L);
        cin >> L;
    }

    vi::iterator it = v.begin();
    while (it != v.end())
    {
        cout << *it << endl;
        it++;
    }
}
int main()
{
    fast_cin();
    solve();
    return 0;
}