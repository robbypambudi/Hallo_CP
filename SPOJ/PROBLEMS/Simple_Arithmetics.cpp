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
#define MAX(a, b) a > b ? a : b
void pmfunction(string &s, int pos, int op)
{
    string rightS = s.substr(0, pos);
    string leftS = s.substr(pos + 1, s.size());

    int rightI = stoi(rightS);
    int leftI = stoi(leftS);
    int result = 0;
    if (op == 1)
    {
        result = rightI + leftI;
        leftS.insert(0, "+");
    }
    else
    {
        result = rightI - leftI;
        leftS.insert(0, "-");
    }

    int tab = MAX(leftS.size(), rightS.size());
    cout << right << setw(tab) << rightI << "\n";
    cout << right << setw(tab) << leftS << "\n";
    string temp;
    forn(tab)
    {
        temp.append("-");
    }
    cout << temp << "\n";

    cout << right << setw(tab) << result << "\n\n";
}
void tdfunction(string &s, int pos, int op)
{
    string leftS, rightS;
    leftS = s.substr(0, pos);
    rightS = s.substr(pos + 1, s.size());

    int leftI = stoi(leftS);
    int rightI = stoi(rightS);

    int result = 0;
    int tab = MAX(leftS.size(), rightS.size()) + rightS.size() - 1;
    if (op == 1)
    {
        result = leftI * rightI;
        rightS.insert(0, "*");
    }
    string temp;
    int underscore = MAX(rightS.size(), leftS.size());
    cout << right << setw(tab) << leftS << "\n";
    cout << right << setw(tab) << rightS << "\n";
    if (rightS.size() > 2)
    {
        forn(underscore)
        {
            temp.append("-");
        }
        cout << right << setw(tab) << temp << "\n";
        int restTemp = 0;
        forn(underscore - 1)
        {
            restTemp = leftI * (rightI % 10);
            rightI /= 10;
            cout << right << setw(tab--) << restTemp << "\n";
        }
    }
    string resultS = to_string(result);
    underscore = resultS.size();
    temp.clear();
    forn(underscore)
    {
        temp.append("-");
    }
    cout << temp << "\n";
    cout << resultS << "\n\n";
}

void solve()
{
    string s = "";
    cin >> s;

    int pos = s.find('+');
    if (pos != -1)
    {
        pmfunction(s, pos, 1);
        return;
    }
    pos = s.find('-');
    if (pos != -1)
    {
        pmfunction(s, pos, 2);
        return;
    }
    pos = s.find('*');
    if (pos != -1)
    {
        tdfunction(s, pos, 1);
        return;
    }
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