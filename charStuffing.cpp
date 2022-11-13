#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);
#define INPUT cin.tie(0);
#define OUTPUT cout.tie(0);
#define ll long long int
#define debug(x) cout << #x << " = " << x << endl;
#define ms(arr, v) memset(arr, v, sizeof(arr)) // assigns v to all elements of arr
#define MAXX (ll)(1e18)
#define lcm(a, b) (a * b) / (__gcd(a, b))
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)
#define endl "\n"
#define frr(i, b, n) for (ll i = b; i < n; ++i)
#define rfrr(i, b, n) for (long i = b; i >= n; --i)
#define pb push_back
#define vll vector<ll>
#define vii vector<int>
#define readv(v, n) \
    frr(i, 0, n)    \
    {               \
        int x;      \
        cin >> x;   \
        v.pb(x);    \
    }
#define printv(v) frr(i, 0, v.size()) cout << v[i] << " ";

using namespace std;

string sender(string s, string flag, string esc)
{
    cout << "initial data to be sent is : " << s << endl;

    for (int i = 0; i < (int)s.length() - (int)8; i++)
    {
        if (s.substr(i, 8) == flag || s.substr(i, 8) == esc)
        {
            s.insert(i, esc);
            i += 8;
        }
    }
    s = flag + s + flag;
    cout << "data sent is " << s << endl;
    return s;
}
string reciever(string s, string flag, string esc)
{
    cout << "data recieved is " << s << endl;
    if (s.substr(0, 8) != flag || s.substr((int)s.length()-(int)8, 8) != flag)
    {
        cout << "error in data recieved" << endl;
        return "";
    }
    s.erase(0, 8);
    s.erase((int)s.length()-(int)8, 8);
    for (int i = 0; i < (int)s.length()-(int)8; i++)
    {
        if (s.substr(i, 8) == esc)
        {
            s.erase(i, 8);
        }
    }
    cout << "data after removing flags is " << s << endl;
    return s;
}

int main()
{
    string s;
    cin >> s;
    string flag = "01111110", esc = "01111101";
    s = sender(s, flag, esc);
    s = reciever(s, flag, esc);

    return 0;
}
