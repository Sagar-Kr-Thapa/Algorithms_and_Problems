// By Sagar Kr Thapa : ST101
/*
 * 
    Determine Euler's Phi Function in O(nlog(logn)) time complexity
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

//displaying the contents of the vector arrays
#define dprint(name,n) rep(i,0,n){cout << name[i] << ' ';}
#define d2print(name,n,m) rep(i,0,n){rep(j,0,m){cout << name[i][j] << ' ';} cout << endl;}


using namespace std;

vec(etf,10000007,1);

void sieveInit()
{
    rep(i,1,10000001)etf[i]=i;

    for( ll i=2; i<=10000001; ++i )
    {
        if( etf[i]==i )
        {
            for( ll j=i; j<=10000001; j+=i )
            {
                etf[j]/=i;
                etf[j]*=(i-1);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    sieveInit();

    while( t-- )
    {
        ll n;
        cin>>n;

        cout << etf[n] << endl;
    }
    return 0;
}