// By Sagar Kr Thapa : ST101
/*
 * 
 *  Two players Alice and Bob are playing a game. They are provided with n piles. The ith pile contains arr[i] number of coins. In each move, a player can choose a pile and remove as many coins as he wants ( minimum 1 coin ). The player who removes the last set of coins wins the game. Alice goes first. 
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

void solve()
{
    //NIM SUM
    ll n;cin>>n;
    vec(arr,n,0);rep(i,0,n)cin>>arr[i];

    ll xsum=arr[0];
    rep(i,1,n)xsum^=arr[i];

    if( xsum )cout<<"ALICE"<<endl;
    else cout << "BOB" << endl;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while( t-- )
    {
        solve();
    }
    return 0;
}