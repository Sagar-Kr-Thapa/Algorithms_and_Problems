// By Sagar Kr Thapa : ST101
/*
 *
    You are given an array a of n integers a1,a2,…,an.

    Your task is to response to the queries like "How many numbers' values are between l and r?".
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

    ll n;
    cin >> n ;

    vec(a,n,0);
    rep(i,0,n)cin>>a[i];
    sort(a.begin(),a.end());

    ll k;
    cin >> k;

    while( k-- )
    {
        ll lb,rb; //left and right bound of the provided segments
        cin >> lb >> rb;


        //rightmost element equal to rb
        ll l=-1; //lower bound
        ll r=n; //upper bound
        while( r>l+1 )
        {
            ll m = (l+r)/2;
            if( a[m]>rb )r=m;
            else l=m;
        }


        //leftmost element equal to lb
        ll l1=-1; //lower bound
        ll r1=n; //upper bound
        while( r1>l1+1 )
        {
            ll m = (l1+r1)/2;
            if( a[m]>=lb )r1=m;
            else l1=m;
        }

        cout << l-r1+1 << '\n';
    }
    return 0;
}