#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define repn(i,a,b) for(ll i=a; i>b; --i)
#define repa(x,container) for( auto x : container )
#define vec(name,no_of_rows,value) vector<ll>name(no_of_rows,value)
#define vec2d(name,no_of_rows,no_of_columns,value) vector<vector<ll>>name(no_of_rows,vector<ll>(no_of_columns,value))
#define vec2da(name,no_of_rows) vector<vector<ll>>name(no_of_rows)
#define sum(vector) accumulate(vector.begin(),vector.end(),0)
#define count(string,ch) count(string.begin(),string.end(),ch)
#define inf INT_MAX

#define dprint(name,n) rep(i,0,n){cout << name[i] << ' ';}
#define d2print(name,n,m) rep(i,0,n){rep(j,0,m){cout << name[i][j] << ' ';} cout << endl;}
using namespace std;

vec2d(dp,105,100005,-1);

ll knapsack( vector<ll>w, vector<ll>v, ll W, ll n)
{
    if( dp[n][W]==-1 )
    {
        if( W==0 || n==0 )dp[n][W]=0;
        else if( w[n-1]<=W ) dp[n][W]=max( v[n-1]+knapsack(w,v,W-w[n-1],n-1), knapsack(w,v,W,n-1));
        else dp[n][W]=knapsack(w,v,W,n-1);
    }
    return dp[n][W];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n, W;
    cin >> n >> W;

    vec(w,n,0);
    vec(v,n,0);

    rep(i,0,n)cin>>w[i]>>v[i];

    cout << knapsack(w,v,W,n) << '\n';

    return 0;
}