// By Sagar Kr Thapa : ST101
/*
 *
    You are given an array A of integers of size N. You will be given Q queries where each query is represented by two integers L, R. You have to find the gcd(Greatest Common Divisor) of the array after excluding the part from range L to R inclusive (1 Based indexing). You are guaranteed that after excluding the part of the array remaining array is non empty.
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

ll gcd( ll a, ll b )
{
    while( b>0 )
    {
        ll t=a;
        a=b;
        b=t%b;
    }

    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while( t-- )
    {
        ll n,q;
        cin>>n>>q;

        vec(a,n,0);rep(i,0,n)cin>>a[i];

        vec(pre,n+2,0);
        vec(suf,n+2,0);

        rep(i,0,n)pre[i+1]=gcd(pre[i],a[i]);
        repn(i,n-1,-1)suf[i]=gcd(suf[i+1],a[i]);

        while( q-- )
        {
            ll l,r;
            cin>>l>>r;

            // dprint(pre,n+2);

            cout << gcd(pre[l-1],suf[r]) << endl;
        }
    }
    return 0;
}