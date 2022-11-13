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

// Cycle Redundancy Check generation
string crc_generation(string data, string divisor)
{
    vii ip, div;
    // cout<<"break";
    for (char c : data)
        ip.push_back(c - '0');
    for (char c : divisor)
        div.push_back(c - '0');
    // debug(div.size());
    
    int n = ip.size(), r = div.size();
    
    for (int i = 0; i < r-1; i++)
        ip.push_back(0);
    int pos = 0;
    while (pos < n)
    {
        int flag=1,nxt=pos+r;
        for (int i = pos; i <pos+ r; i++)
        {
            ip[i] ^= div[i-pos];
            if(flag && ip[i])
            flag=0,nxt=i;
        }
        // debug(nxt)
        pos = nxt;
    }
    string red;
    for (int i = n; i < n + r - 1; i++)
        red += to_string(ip[i]);
    string op = data + red;
    cout<<op;
    cout<<endl;
    return op;
}
// crc detection
void crc_detection(string data, string divisor)
{
    vii ip, div;
    // cout<<"break";
    for (char c : data)
        ip.push_back(c - '0');
    for (char c : divisor)
        div.push_back(c - '0');
    // debug(div.size());
    
    int n = ip.size(), r = div.size();
    debug(data) debug(r);
    int pos = 0;
    while (pos < n-r+1)
    {
        int flag=1,nxt=pos+r;
        for (int i = pos; i <pos + r; i++)
        {
            ip[i] ^= div[i-pos];
            if(flag && ip[i])
            flag=0,nxt=i;
        }
        // debug(nxt)
        pos = nxt;
    }
    int flag=0;
    
    for (int i = n-r; i < n; i++)
    {

        if(ip[i])
        {
            flag=1;
            break;
        }
    }
    if(flag)
    cout<<"Error detected";
    else
    cout<<"No error detected";

}

int main()
{
    // FAST INPUT OUTPUT
    string s;
    cin >> s;
    // int n=ip.length();
    string div="1001";
    crc_detection(crc_generation(s,div),div);
    return 0;
}
