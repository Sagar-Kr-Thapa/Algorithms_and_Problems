// By Sagar Kr Thapa : ST101
/*
 * 
 *  Minimum Bit Flips to make a OR b equal to c? 
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

int minFlips( int a, int b, int c )
{
    int res=0;
    for( int i=0; i<32; ++i )
    {
        bool x=false,y=false,z=false; // for a,b,c
        if( a&(1<<i) )x=true;
        if( b&(1<<i) )y=true;
        if( c&(1<<i) )z=true;

        if( z==true )
        {
            if( x==false && y==false )res++;
        }
        else
        {
            if( x==true && y==true )res+=2;
            else if( x==true || y==true )res++;
        }
    }

    return res;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;
    cin >> a >> b >> c;

    cout << minFlips(a,b,c) << endl;
    return 0;
}