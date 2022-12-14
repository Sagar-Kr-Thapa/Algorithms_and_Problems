// By Sagar Kr Thapa : ST101
/*
 * 
    Stalls are located on a straight line, your task is to arrange the cows to stalls so that the minimum distance between the cows is as large as possible. 
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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n;
    cin >> k;

    vector<ll>a(n);

    rep(i,0,n)cin >> a[i];

    auto isGood=[&](ll s)
    {
        ll segments=1;
        ll temp_sum=0;

        rep(i,0,n)
        {
            if( temp_sum+a[i]>s )
            {
                ++segments;
                temp_sum=0;
            } 
            if( segments>k || a[i]>s ) return false;

            temp_sum+=a[i];
        }
        return true;
    };
    
    ll l=0;
    ll r=1e15;

    while( r>l+1 ) 
    {
        ll m=(l+r)/2;
        if( !isGood(m) )r=m;
        else l=m;
    }

    cout << r << '\n';

    return 0;
}