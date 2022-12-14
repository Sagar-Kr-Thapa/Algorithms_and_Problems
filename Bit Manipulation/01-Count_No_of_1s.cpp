// By Sagar Kr Thapa : ST101
/*
 * 
 *  Hamming Weight 
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


ll hammingWeight( ll n )
{ 
    //way 1
    {
        ll count=0;
        while( n )
        {
            ++count;
            n=n&(n-1);
        }
        return count;
    }

    //way 2
    {
        ll cnt=0;
        while( n )
        {
            cnt+=n&1;
            n>>=1;
        }
        return cnt;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unsigned ll t;
    cin >> t;

    cout << hammingWeight(t) << '\n';
    return 0;
}