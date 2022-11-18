// By Sagar Kr Thapa : ST101
/*
 * 
    Given an array of n integers ai. Let's say that a segment of this array a[l..r] (1≤l≤r≤n) is good if there are no more than k unique elements on this segment. Your task is to find the number of different good segments.
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

    ll n,k;
    cin >> n >> k;

    vec(a,n,0);
    vec(cnt,100005,0);
    rep(i,0,n)
    {
        cin>>a[i];
    }

    ll l=0;
    ll num=0;
    ll segments=0;

    rep(r,0,n)
    {
        {
            cnt[a[r]]++;
            if( cnt[a[r]]==1 )num++;
        }
        while( num>k )
        {
            cnt[a[l]]--;
            if( cnt[a[l]]==0 )num--;
            l++; 
        }

        segments+=r-l+1;
    }

    cout << segments << '\n';

    return 0;
}