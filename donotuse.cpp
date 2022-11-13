#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0);
#define INPUT cin.tie(0);
#define OUTPUT cout.tie(0);
#define ll long long int
#define debug(x) cout << #x << " = " << x << endl;
#define endl "\n"
#define frr(i, b, n) for (ll i = b; i < n; ++i)
#define rfrr(i, b, n) for (long i = b; i >= n; --i)
#define pb push_back
#define vll vector<ll>
#define vii vector<int>

using namespace std;

string checksum_generator(string ip, int n)
{
    int k = ceil((double)ip.length() / (double)n);
    debug(k);
    vector<string> v(k);
    int x = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n && x < ip.length(); j++)
        {
            v[i] += ip[x++];
        }
    }
    if (v[k - 1].length() < n)
    {
        for (int i = v[k - 1].length(); i < n; i++)
        {
            v[k - 1] = '0' + v[k-1];
        }
    }
    // for(string s:v)
    // cout<<s<<endl;
    string checksum;
    int carry = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int sum = carry;
        for (int j = 0; j < k; j++)
        {
            sum += v[j][i] - '0';
        }
        cheksum = ((sum % 2) + '0')  + checksum;
        carry = sum;
    }
    cout<<checksum;

    string ans = "";
    return ans;
}

int main()
{
    FAST INPUT OUTPUT
        string s;
    cin >> s;
    int n=5;
    string ans = checksum_generator(s, n);

    return 0;
}
