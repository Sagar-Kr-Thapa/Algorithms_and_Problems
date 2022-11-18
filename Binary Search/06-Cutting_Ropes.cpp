// By Sagar Kr Thapa : ST101
/*
 * 
    There are n ropes, you need to cut k pieces of the same length from them. Find the maximum length of pieces you can get.


    MAXIMUM GOOD NUMBER
    111111111110000000000000
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

ll n,k;
vector<ld>a;

bool isGood( ld m )
{
    ll sum=0;
    rep(i,0,n)
    {
        sum+=floor(a[i]/m);
    }

    return sum>=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    a.resize(n);
    rep(i,0,n)cin>>a[i];

    ld l=0; //left bound
    ld r=1e8; //right bound

    rep(i,0,100) //the answer is double
    {
        ld m=(l+r)/2;
        if( isGood(m) )l=m;
        else r=m;
    }

    cout << setprecision(20);
    cout << l << '\n';
    
    return 0;
}