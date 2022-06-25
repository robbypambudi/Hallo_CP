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

bool checkNines(string &s)
{
    forn(s.size())
    {
        if (s[i] != '9')
        {
            return false;
        }
    }
    return true;
}
bool checkZerro(string &s)
{
    forn(s.size())
    {
        if (s[i] != '0')
        {
            return false;
        }
    }
    return true;
}

void toPair(ll x, ll *leftP)
{
    if (x % 2 == 0)
    {
        *leftP -= 1;
    }
}
void solve()
{
    string s;
    cin >> s;

    if (checkNines(s))
    {
        cout << 1;
        forn(s.size() - 1)
        {
            cout << 0;
        }
        cout << 1 << "\n";
        return;
    }
    if (checkZerro(s))
    {
        cout << 1;
        forn(s.size() - 2)
        {
            cout << 0;
        }
        cout << 1 << "\n";
        return;
    }

    ll len = s.size();

    ll leftP;
    ll rightP;

    leftP = rightP = len / 2;

    toPair(len, &leftP);
    // cout << leftP << rightP;

    while (leftP >= 0 && s[leftP] == s[rightP])
    {
        leftP--;
        rightP++;
    }

    if (leftP < 0 || s[leftP] < s[rightP])
    {

        rightP = leftP = len / 2;

        toPair(len, &leftP);

        ll carry = 1;

        while (leftP >= 0)
        {
            ll num = (s[leftP] - '0') + carry;
            carry = num / 10;
            s[leftP] = (num % 10) + '0';
            s[rightP] = s[leftP];
            leftP--;
            rightP++;
        }
    }
    else
    {
        while (leftP >= 0)
        {
            s[rightP] = s[leftP];
            rightP++;
            leftP--;
        }
    }
    cout << s << "\n";
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    forn(t)
    {
        solve();
    }
    return 0;
}