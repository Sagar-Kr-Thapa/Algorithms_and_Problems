// By Sagar Kr Thapa : ST101
/*
 * 
    There are n people on a straight line, they need to gather at one point. Each person knows his current position xi and his speed vi. Help them find out in what minimum time they can gather at one point.
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

    ll n;
    cin >> n;

    vector<ld>pos(n);
    vector<ld>vel(n);

    rep(i,0,n)cin >> pos[i] >> vel[i];

    auto isGood=[&](ld x)
    {
        ld lx=-1e9;
        ld rx=1e9;

        rep(i,0,n)
        {
            ld temp_lx=pos[i]-(x*vel[i]);
            ld temp_rx=pos[i]+(x*vel[i]);

            if( temp_lx>rx || temp_rx<lx )return false;

            lx=max(lx,temp_lx);
            rx=min(rx,temp_rx);
        }
        return true;
    };
    
    ld l=0;
    ld r=1e10;

    rep(i,0,100) 
    {
        ld m=(l+r)/2.0;
        if( isGood(m) )r=m;
        else l=m;
    }

    cout << setprecision(20);
    cout << r << '\n';

    return 0;
}