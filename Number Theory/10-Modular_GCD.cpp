// By Sagar Kr Thapa : ST101
/*
 * 
    Given integers A, B and N, you should calculate the GCD of A^N + B^N and |A - B|. (Assume that GCD(0, a)=a for any positive integer a). Since this number could be very large, compute it modulo 1000000007 (10^9 + 7).
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

ll power( ll base, ll n, ll d )
{
    //using binary exponentiation
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


void solve()
{
    ll a,b,n;
    cin>>a>>b>>n;


    if( a==b )
    {
        cout << (power(a,n,mod)+power(b,n,mod))%mod << endl;
        return;
    }

    //Finding potential gcd candidates
    ll num=a-b;
    ll cd=1; //candidate

    for( ll i=2; i*i<=num; ++i )
    {
        if( num%i==0 )
        {
            ll tmp=(power(a,n,i)+power(b,n,i))%i;
            if( tmp==0 )cd=max(cd,i);

            tmp=(power(a,n,num/i)+power(b,n,num/i))%(num/i);
            if( tmp==0 )cd=max(cd,num/i);
        }
    }

    cout << cd%mod << endl;
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