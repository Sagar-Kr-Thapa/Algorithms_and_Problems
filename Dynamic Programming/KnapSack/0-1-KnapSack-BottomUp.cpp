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

vec2d(dp,105,100005,0);

ll knapsack( vector<ll>w, vector<ll>v, ll W, ll n)
{
    //no need for initialization

    //Bottom Up 
    rep(i,1,n+1)
    {
        rep(j,1,W+1)
        {
            if( w[i-1]<=j )dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
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