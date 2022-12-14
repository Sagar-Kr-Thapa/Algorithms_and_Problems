// By Sagar Kr Thapa : ST101
/*
 * 
 *  Sum on a Rectangle 
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

    ll n,m;
    cin>>n>>m;

    vec2d(a,n,m,0);
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            cin>>a[i][j];
        }
    }

    // d2print(a,n,m);

    //2D-prefix sum
    vec2d(p,n+1,m+1,0);
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            p[i+1][j+1]=p[i][j+1]+p[i+1][j]-p[i][j]+a[i][j];
        }
    }

    // d2print(p,n+1,m+1);

    ll t;
    cin >> t;

    while( t-- )
    {

        ll lx,rx,ly,ry;
        cin>>lx>>ly>>rx>>ry;

        ll sum = p[rx][ry]-p[lx-1][ry]-p[rx][ly-1]+p[lx-1][ly-1];
        cout << sum << '\n';

    }

    return 0;
}