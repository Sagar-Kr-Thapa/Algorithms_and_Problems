// By Sagar Kr Thapa : ST101
/*
 *
    The organizers of the children's holiday are planning to inflate m balloons for it. They invited n assistants, the i-th assistant inflates a balloon in ti minutes, but every time after zi balloons are inflated he gets tired and rests for yi minutes. Now the organizers of the holiday want to know after what time all the balloons will be inflated with the most optimal work of the assistants, and how many balloons each of them will inflate. (If the assistant has inflated the balloon and needs to rest, but he will not have to inflate more balloons, then it is considered that he finished the work immediately after the end of the last balloon inflation, and not after the rest).
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

ll m,n;
vector<ll>t,z,y;
vector<ll>balloons;

ll blown( ll i, ll x )
{
    ll exact=(x/(t[i]*z[i]+y[i]))*z[i];
    ll extra=min((x%(t[i]*z[i]+y[i]))/t[i],z[i]);   

    return exact+extra;
}


bool isGood( ll x )
{
    ll count=0;
    rep(i,0,n)
    {
        count += blown(i,x);
    }

    return count>=m;    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    t.resize(n);
    z.resize(n);
    y.resize(n);
    balloons.resize(n,0);

    rep(i,0,n)cin>>t[i]>>z[i]>>y[i];

    ll l=-1; //lower bound
    ll r=1e10; //upper bound

    while( r>l+1 ) 
    {
        ll mid=(l+r)/2;
        if( isGood(mid) )r=mid;
        else l=mid;
    }


    {
        cout << r << '\n';
        rep(i,0,n)
        {
            ll balloonNum=min(m,blown(i,r));
            cout << balloonNum << " ";
            m-=balloonNum; //balloonNum is already blown
        }
    }
    return 0;
}