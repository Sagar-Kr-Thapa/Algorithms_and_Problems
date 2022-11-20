// By Sagar Kr Thapa : ST101
/*
 * 
 *  The array contains elements with frequency 3 except one. Can you find THE ONE? 
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

#define endl '\n'

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int  n;
    cin >> n;

    vector<int> a(n,0);

    // f[i]=number of elements whose ith bit is set
    vector<int> f(32,0);
    for( int i=0; i<n; ++i ) cin>>a[i];

    for( const int &e : a )
    {
        for( int i=0; i<32; ++i )
        {
            //check if the ith bit is set
            if( e&(1<<i) )
            f[i]++;
        }
    }

    int res=0;
    for( int i=0; i<32; ++i )
    {
        if( f[i]%3 )res+=(1<<i);
    }

    cout << res << endl;

    return 0;
}