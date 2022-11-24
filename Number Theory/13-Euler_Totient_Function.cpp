// By Sagar Kr Thapa : ST101
/*
 * 
    ETF in O(sqrt(N)) time complexity
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

ll phi( ll n )
{
    if( n==2 )return 1;
    else if( n==3 )return 2;

    ll result=n;

    for(ll i=2; i*i<=n; ++i )
    {
        if( n%i==0 )
        {
            result*=(i-1);
            result/=i;
            while( n%i==0 )n/=i;
        }
    }

    if( n>1 )
    {
        result*=(n-1);
        result/=n;
    }

    return result;
}

void solve()
{
    ll n;
    cin>>n;

    cout << phi(n) << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while( t-- )
    {
        solve(); 
    }
    return 0;
}