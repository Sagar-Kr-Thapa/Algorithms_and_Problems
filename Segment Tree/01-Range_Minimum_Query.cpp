/*
 * 
    You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the minimum number between the range [i, j] (inclusive).

    Note: the query ranges are specified using 0-based indexing.
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
#define linf LLONG_MAX

//displaying the contents of the vector arrays
#define dprint(name,n) rep(i,0,n){cout << name[i] << ' ';}
#define d2print(name,n,m) rep(i,0,n){rep(j,0,m){cout << name[i][j] << ' ';} cout << endl;}


using namespace std;

vec(st,1000000,0);

void buildTree( vector<ll>&a, ll si, ll ss, ll se )
{
    if( ss==se )st[si]=a[ss]; // leaf node
    else
    {
        ll mid=(ss+se)/2;
        buildTree( a, 2*si, ss, mid); // left child
        buildTree( a, 2*si+1, mid+1, se); // right child

        st[si]=min(st[2*si],st[2*si+1]);
    }
}

ll queryTree( ll si, ll ss, ll se, ll qs, ll qe)
{
    if( qe<ss || qs>se )return linf;
    if( se<=qe && ss>=qs )return st[si];
    // if( qe<=se && qs>=ss )return st[si];
    
    ll mid=(ss+se)/2;

    ll l=queryTree(2*si,ss,mid,qs,qe);
    ll r=queryTree(2*si+1,mid+1,se,qs,qe);

    return min(l,r);
}

void solve()
{
    ll n;cin>>n;
    vec(a,n+1,0);
    rep(i,1,n+1)cin>>a[i];

    buildTree(a,1,1,n);

    ll q;cin>>q;
    while( q-- )
    {
        ll i,j;
        cin>>i>>j;

        cout << queryTree(1,1,n,i+1,j+1)<<endl;
    }

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ll t;
    // cin >> t;

    // while( t-- )
    {
        solve()        ;
    }
    return 0;
}