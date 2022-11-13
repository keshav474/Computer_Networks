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

string sender(string s)
{
    cout << "initial data to be sent is : " << s << endl;
    debug(s.length())
    for (int i = 0; i < s.length() - 4; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1' && s[i + 3] == '1' && s[i + 4] == '1')
        {
            s.insert(i + 5, "0");
            i += 5;
        }
    }
    s = "01111110" + s + "01111110";

    cout << "data sent is " << s << endl;
    return s;
}
string reciever(string s)
{
    cout << "data recieved is " << s << endl;
    if (s.substr(0, 8) != "01111110" || s.substr(s.length() - 8, 8) != "01111110")
    {
        cout << "error in data recieved" << endl;
        return "";
    }
    s.erase(0, 8);
    s.erase(s.length() - 8, 8);
    for (int i = 0; i < s.length() - 4; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '1' && s[i + 3] == '1' && s[i + 4] == '1' && s[i + 5] == '0')
        {
            s.erase(i + 5, 1);
            i += 5;
        }
    }
    cout << "data recieved after removing flags is " << s << endl;
    return s;
}

int main()
{
    FAST INPUT OUTPUT
        string s;
    cin >> s;

    reciever(sender(s));

    return 0;
}
