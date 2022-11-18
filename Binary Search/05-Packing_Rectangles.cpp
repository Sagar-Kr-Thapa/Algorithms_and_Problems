// By Sagar Kr Thapa : ST101
/*
 * 
    There are n rectangles of the same size: w in width and h in length. It is required to find a square of the smallest size into which these rectangles can be packed. Rectangles cannot be rotated.


    
    MINIMUM GOOD NUMBER
    000000000000011111111111
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

ll w,h,n;

bool isGood( ll m )
{
    return (m/w)*(m/h)>=n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> n;

    ll l=0; //left bound
    ll r=1; //right bound

    //adjusting right bound
    while( !isGood(r) ) r*=2;

    while( r>l+1 )
    {
        ll m=(l+r)/2;
        if( isGood(m) )r=m;
        else l=m;
    }

    cout << r << '\n';
    
    return 0;
}