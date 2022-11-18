// By Sagar Kr Thapa : ST101
/*
 * 
    This morning the jury decided to add one more, Very Easy Problem to the problemset of the olympiad. The executive secretary of the Organizing Committee has printed its statement in one copy, and now they need to make n more copies before the start of the olympiad. They have two copiers at his disposal, one of which copies a sheet in x seconds, and the other in y seconds. (It is allowed to use one copier or both at the same time. You can copy not only from the original, but also from the copy.) Help them find out what is the minimum time they need to make n copies of the statement.
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

ll n,x,y;

bool isGood( ll m )
{
    return (m/x)+(m/y)+1>=n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;

    ll l=-1; //lower bound
    ll r=1e10; //upper bound

    while( r>l+1 )
    {
        ll m=(l+r)/2;
        if( isGood(m) )r=m;
        else l=m;
    }

    cout << r+min(x,y) << '\n';

    return 0;
}