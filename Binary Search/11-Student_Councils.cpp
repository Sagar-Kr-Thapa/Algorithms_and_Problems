// By Sagar Kr Thapa : ST101
/*
 * 
    Given the number k. Each student council must consist of k students. Important rule: each council should be composed of students from different groups. That is, no two students from the same group can be in the same council.

    Of course, each student should be in no more than one council (it is possible that some students are not included in any).

    An array a[1..n] is given, where a[i] is the number of students in the i-th group. What is the maximum number of councils can be formed?
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
#define inf LLONG_MAX

//displaying the contents of the vector arrays
#define dprint(name,n) rep(i,0,n){cout << name[i] << ' ';}
#define d2print(name,n,m) rep(i,0,n){rep(j,0,m){cout << name[i][j] << ' ';} cout << endl;}


using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> k >> n;

    vec(a,n,0);
    rep(i,0,n)cin>>a[i];

    auto isGood = [&]( ll x )
    {
        ll total=0;
        rep(i,0,n)
        {
            total+=min(x,a[i]);
        }

        return total >= (x*k);
    };
    
    ll l=-1; //lower bound
    ll r=1e9;  //upper bound

    while( r>l+1 )
    {
        ll m=(l+r)/2;
        if( isGood(m) )l=m;
        else r=m; 
    }
    cout << l << '\n';
    return 0;
}