// By Sagar Kr Thapa : ST101
/*
 * 
 *  Given q queries of type n,k , Calculate C(n,k)%p where p is a prime number and p>n.
 * 
*/


#include<bits/stdc++.h>

//MACROS
#define ll long long
//for loops
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define repn(i,a,b) for(ll i=a; i>b; --i)
#define repa(x,container) for( auto x : container )

//1D and 2D vector arrays
#define vec(name,no_of_rows,value) vector<ll>name(no_of_rows,value)
#define vec2d(name,no_of_rows,no_of_columns,value) vector<vector<ll>>name(no_of_rows,vector<ll>(no_of_columns,value))
#define vec2da(name,no_of_rows) vector<vector<ll>>name(no_of_rows)

#define sum(vector) accumulate(vector.begin(),vector.end(),0)
#define count(string,ch) count(string.begin(),string.end(),ch)
#define inf INT_MAX

#define mod 1000000007

//displaying the contents of the vector arrays
#define dprint(name,n) rep(i,0,n){cout << name[i] << ' ';}
#define d2print(name,n,m) rep(i,0,n){rep(j,0,m){cout << name[i][j] << ' ';} cout << endl;}


using namespace std;

ll power( ll a, ll n, ll d )
{
    //using binary exponentiation 
    ll result=1;
    ll base=a;
    while( n>0 )
    {
        if( n%2 )
        {
            n--;
            result = ((result%d)*(base%d))%d;
        }
        else
        {
            n/=2;
            base = ((base%d)*(base%d))%d;
        }
    }

    return result;
}

ll inv( ll x )
{
    return power(x,mod-2,mod);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll q;
    cin >> q;

    //pre-processing 
    vec(fac,10000009,1);
    rep(i,2,1000000)
        fac[i]=(fac[i-1]*i)%mod;

    while( q-- )
    {
        ll n,k;cin>>n>>k;

        if( k>n )
        {
            cout<<0<<endl; 
            continue;
        }

        ll result=fac[n];
        // cout << power(fac[k],mod-2,mod) << endl;
        result = (result * power(fac[k],mod-2,mod))%mod;
        // cout << fac[n-k] << endl;
        result = (result * inv(fac[n-k]))%mod;

        cout << result << endl;
    }
    return 0;
}