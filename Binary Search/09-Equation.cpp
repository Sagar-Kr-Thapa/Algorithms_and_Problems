// By Sagar Kr Thapa : ST101
/*
 * 
    Find a number x such that x^2+sq(x)=c.
 * 
*/


#include<bits/stdc++.h>

//MACROS
#define ll long long
#define ld long double 
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

    ld c;
    cin >> c; 

    ld l=-1; //lower bound
    ld r=1e5; //upper bound

    auto isGood=[&](ld x)
    {
        return pow(x,2)+sqrt(x)>=c;
    };

    rep(i,0,100)
    {
        ld m=(l+r)/2;
        if( isGood(m) )r=m;
        else l=m;
    }

    cout << setprecision(15);
    cout << r << '\n';

    return 0;
}