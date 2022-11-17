// By Sagar Kr Thapa : ST101
/*
 * 
 * Variation of KnapSack Problems 
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

vector<vector<bool>>dp(102,vector<bool>(100005,false));

bool subsetSum( vector<ll>w, ll W, ll n)
{
    //initialization
    rep(i,0,n+1)
    {
        rep(j,0,W+1)
        {
            if( i==0 )dp[i][j]=false;
            if( j==0 )dp[i][j]=true;
        }
    }

    //body
    rep(i,1,n+1)
    {
        rep(j,1,W+1) 
        {
            if( w[i-1]<=j )dp[i][j]=dp[i-1][j-w[i-1]] || dp[i-1][j];
            else dp[i][j]=dp[i-1][j];
        }
    } 

    return dp[n][W];
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,sum;
    cin >> n >> sum;

    vec(arr,n,0);
    
    rep(i,0,n)cin>>arr[i];

    bool subsetExist = subsetSum(arr,sum,n);

    if( subsetExist ) cout << "YES\n";
    else cout << "NO\n";

    
    return 0;
}

