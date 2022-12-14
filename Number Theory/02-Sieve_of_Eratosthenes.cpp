// By Sagar Kr Thapa : ST101

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

vector<ll>primes;
vector<bool>arr(90000001,true);

void sieve()
{
    ll maxN=90000000;
    arr[0]=arr[1]=false;

    for( ll i=2; i*i<=maxN; ++i )
    {
        if( arr[i] )
        {
            for( ll j=i*i; j<=maxN; j+=i )arr[j]=false;
        }
    }

    rep(i,0,maxN+1)
    {
        if ( arr[i] )primes.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    sieve();
    
    while( t-- )
    {
        ll k;
        cin>>k;
        cout<<primes[k-1]<<endl;
    }
    return 0;
}