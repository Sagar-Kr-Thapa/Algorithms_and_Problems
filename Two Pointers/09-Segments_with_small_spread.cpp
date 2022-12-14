/*
 * 
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


struct stack{
    vector<ll>s,smin={LLONG_MAX},smax={LLONG_MIN};

    void push( ll x )
    {
        s.push_back(x);
        smin.push_back(::min(smin.back(),x));
        smax.push_back(::max(smax.back(),x));
    } 

    ll pop()
    {
        ll r=s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return r;
    }

    bool empty()
    {
        return s.empty();
    }

    ll max()
    {
        return smax.back();
    }

    ll min()
    {
        return smin.back();
    }

};

::stack s1,s2;


void add( ll x )
{
    s2.push(x);
}

void remove()
{
    if( s1.empty() )
    {
        while( !s2.empty() )
        {
            s1.push(s2.pop());
        }
    }
    s1.pop();
}

ll k;

bool good()
{
    ll miN=min(s1.min(),s2.min());
    ll maX=max(s1.max(),s2.max());

    return (maX-miN)<=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n >> k;

    vec(a,n,0);
    rep(i,0,n)cin>>a[i];

    ll segments=0;
    ll l=0;
    rep(r,0,n)
    {
        add(a[r]);
        while( !good() )
        {
            remove();
            l++;
        }
        segments+=r-l+1;
    }

    cout << segments << '\n';

    return 0;
}