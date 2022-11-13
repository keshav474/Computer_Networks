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

// hamming code generation
vii hamming_code_generation(string dataword)
{
    int n = dataword.length();
    int r = 0;
    while (pow(2, r) < n + r + 1)
    {
        r++;
    }
    int m = n + r + 1;
    vector<int> op(m, r);
    int j = 0, k = n - 1;
    for (int i = 1; i < m; i++)
    {
        if (i == pow(2, j))
        {
            j++;
        }
        else
        {
            op[i] = dataword[k--] - '0';
        }
    }
    for (int i = 0; pow(2, i) < m; i++)
    {
        int pos = pow(2, i);
        // debug(pos);
        int parity = 0;
        for (int j = pos; j < m; j += 2 * pos)
        {
            // debug(j);
            for (int k = j; k < j + pos && k < m; k++)
            {
                // debug(k);
                if (k != pos)
                    parity ^= op[k];
            }
        }
        // debug(parity)
            op[pos] = parity;
    }
    vii res(op);

    reverse(op.begin(), op.end());
    op.pop_back();
    cout<<"Hamming code is : ";
    for (int a : op)
    {
        cout << a << " ";
    }
    cout << endl;
    for (int a :res)
    {
        cout << a << " ";
    }
    cout << endl;

    return res;
}

// hamming code detection
void hamming_code_detection(vector<int> v)
{
    int m=v.size();
    int r=v[0];
    debug(r)
    int error = 0, p=0;
    for(int i=1; i<m; i=i*2)
    {
        int parity = 0;
        for(int j=i; j<m; j+=2*i)
        {
            for(int k=j; k<j+i && k<m; k++)
            {
                // if(k!=i)
                parity ^= v[k];
            }
        }
        error += parity*pow(2, p++);
    }
    cout<<endl;

    if(error==0)
    {
        cout<<"No error detected"<<endl;
    }
    else
    {
        cout<<"Error detected at position "<<error<<endl;
    }
    v[error]=!v[error];
    // cout<<"Corrected code is : ";
    // for(int a:v)
    // {
    //     cout<<a<<" ";
    // }
    cout<<"Correct data is : ";
    p=0;
    vector<int> res;
    for(int i=1; i<m; i++)
    {
        if(i==pow(2, p))
        {
            p++;
        }
        else
        {
            res.push_back(v[i]);
        }
    }
    reverse(res.begin(), res.end());
    for(int a:res)
    {
        cout<<a<<" ";
    }
    cout<<endl;


}
    

int main()
{
    FAST INPUT OUTPUT
        string ip;
    cin >> ip;
    // int n=ip.length();
    hamming_code_detection(hamming_code_generation(ip));

    return 0;
}
