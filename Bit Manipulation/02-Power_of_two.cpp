// By Sagar Kr Thapa : ST101
/*
 * 
 *  Is the given number power of 2? 
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

bool powerOfTwo( ll n ) 
{
    // First way
    /*
    You can count the number of setbits by using the previous algorithm and if the count is equal to one then the number is a power of two.
    */

    // Second way
    if ( n<=0 ) return false;
    
    if( n&(n-1) ) return false;
    else return true; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    if( powerOfTwo(t) )cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}