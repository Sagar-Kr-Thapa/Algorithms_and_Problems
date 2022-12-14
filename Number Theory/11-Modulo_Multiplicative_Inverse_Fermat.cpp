// By Sagar Kr Thapa : ST101
/*
 * 
    Finding the modulo multiplicative inverse of a number using Fermat's Little Theorem
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

ll modInv( ll a, ll n, ll d )
{

    // using binary exponentiation
    ll base=a;
    ll result=1;
    while( n>0 )
    {
        if( n%2 )
        {
            n--;
            result = ((result%d) * (base%d))%d;
        }
        else 
        {
            n/=2;
            base = ((base%d) * (base%d))%d;
        }
    }
    return result;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while( t-- )
    {
        ll a,m; //here m should a prime number and  a & m should be coprime, i.e. gcd(m,a)=1;
        cin>>a>>m;

        //The modulo multipicative inverse of a is 
        cout << modInv(a,m-2,m) << endl;
    }
    return 0;
}