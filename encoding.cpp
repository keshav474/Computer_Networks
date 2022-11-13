#include<bits/stdc++.h>
#define FAST     ios_base::sync_with_stdio(0);
#define INPUT    cin.tie(0);
#define OUTPUT   cout.tie(0);
#define ll       long long int
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define ms(arr, v) memset(arr, v, sizeof(arr)) //assigns v to all elements of arr
#define MAXX (ll)(1e18)
#define lcm(a,b) (a*b)/(__gcd(a,b))
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define endl     "\n"
#define frr(i, b, n) for (ll i = b; i < n; ++i)
#define rfrr(i, b, n) for (long i = b; i >= n; --i)
#define pb push_back
#define vll vector<ll>
#define vii vector<int>
#define readv(v,n) frr(i,0,n){int x;cin>>x;v.pb(x);}
#define printv(v)  frr(i,0,v.size())cout<<v[i]<<" ";


using namespace std;
 
void unipolar(string s)
{
   cout<<"unipolar encoding"<<endl;
   cout<<"ip : ";
   for(char c:s)
   cout<<c<<" ";
    cout<<endl<<"op : ";

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            cout<<"0 ";
        }
        else
        {
            cout<<"+ ";
        }
    }
    cout<<endl;
}

void nrzl(string s)
{
    cout<<"NRZL encoding"<<endl;
    cout<<"ip : ";
    for(char c:s)
    cout<<c<<" ";
    cout<<endl<<"op : ";

    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            cout<<"- ";
        }
        else
        {
            cout<<"+ "  ;
        }
    }
    cout<<endl;
}
void nrzi(string s)
{
    cout<<"NRZI encoding"<<endl;
    cout<<"ip : ";
    for(char c:s)
    cout<<c<<" ";
    cout<<endl<<"op : ";

    int prev=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            if(prev==1)
            {
                cout<<"- ";
                prev=-1;
            }
            else
            {
                cout<<"+ ";
                prev=1;
            }
        }
        else
        {
            if(prev==1)
            {
                cout<<"+ ";
            }
            else
            {
                cout<<"- ";
            }
        }
    }
    cout<<endl;
}
void rz(string s)
{
    cout<<"RZ encoding "<<endl;
    cout<<"ip : ";
    for(int i=0;i<s.length();i++)
    {
        cout<<" "<<s[i]<<"   ";
    }
    cout<<endl;
    cout<<"op : ";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            cout<<"- 0  ";
        }
        else
        {
            cout<<"+ 0  ";
        }
        
    }
    cout<<endl;
}

void manchester(string s)
{
    cout<<"Manchester encoding"<<endl;
    cout<<"ip : ";
    for(int i=0;i<s.length();i++)
    {
        cout<<" "<<s[i]<<"   ";
    }
    cout<<endl;
    cout<<"op : ";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            cout<<"+ -  ";
        }
        else
        {
            cout<<"- +  ";
        }
        
    }
    cout<<endl;
}

void differential_manchester(string s)
{
    cout<<"Differential Manchester encoding"<<endl;
    cout<<"ip : ";
    for(int i=0;i<s.length();i++)
    {
        cout<<" "<<s[i]<<"   ";
    }
    cout<<endl;
    cout<<"op : ";
    int prev=1;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
        {
            if(prev==1)
            {
                cout<<"+ -  ";
                prev=-1;
            }
            else
            {
                cout<<"- +  ";
                prev=1;
            }
        }
        else
        {
            if(prev==1)
            {
                cout<<"- +  ";
            }
            else
            {
                cout<<"+ -  ";
            }
        }
        
    }
    cout<<endl;
}

void ami(string s)
{
    cout<<"AMI encoding"<<endl;
    cout<<"ip : ";
    for(int i=0;i<s.length();i++)
    {
        cout<<""<<s[i]<<" ";
    }
    cout<<endl;
    cout<<"op : ";
    int prev=1;
    string mark="+-";
    for(char c:s)
    {
        if(c=='0')
        cout<<"0 ";
        else
        cout<<mark[prev=!prev]<<" ";
    }
    cout<<endl;
}

int main()
{
    string s;
    cin>>s;
    unipolar(s);
    nrzl(s);
    nrzi(s);
    rz(s);
    manchester(s);
    differential_manchester(s);
    ami(s);
    return 0;
}
