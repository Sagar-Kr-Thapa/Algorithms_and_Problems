// By Sagar Kr Thapa : ST101
/*
 * 
 *  Find M^n (where, M is a kxk square matrix and n is an integer) in O(k^3 * logn) time complexity 
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


#define DIM 101

ll A[DIM][DIM];
ll I[DIM][DIM];

#define MOD 1000000007

void mul( ll A[][DIM], ll B[][DIM], ll dim)
{
    ll R[dim+1][dim+1];

    rep(i,1,dim+1)
    {
        rep(j,1,dim+1)
        {
            R[i][j]=0;
            rep(k,1,dim+1)R[i][j]=(R[i][j]+A[i][k]*B[k][j])%MOD;
        }
    }

    rep(i,1,dim+1)
    {
        rep(j,1,dim+1) A[i][j]=R[i][j];
    }
}

void print( ll A[][DIM], ll dim )
{
    rep(i,1,dim+1)
    {
        rep(j,1,dim+1)cout<<A[i][j]<<' ';
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while( t-- )
    {
        ll k,n; //dimension and power
        cin >> k >> n;

        //INPUT
        rep(i,1,k+1)rep(j,1,k+1)cin>>A[i][j];

        //initialize result
        rep(i,1,k+1)
        {
            rep(j,1,k+1)
            {
                if( i==j )I[i][j]=1;
                else I[i][j]=0;
            }
        }

        while( n>0 )
        {
            if( n%2 )
            {
                n--;
                mul(I,A,k);
            }
            else
            {
                mul(A,A,k);
                n/=2;
            }
        }

        //result is stored in I 
        print(I, k);
    }
    return 0;
}