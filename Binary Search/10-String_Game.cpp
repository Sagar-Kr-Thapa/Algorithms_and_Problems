// By Sagar Kr Thapa : ST101
/*
 * 
    Petya has the word t, he wants to make the word p from it. Petya begins to delete the letters in a certain order, which is described as a permutation of indices of the letters of the word t: a1…a|t|. Note that after deleting a letter, the numbering does not change.

    His brother Vasya is afraid that Petya may delete too many letters, so he will not get the word p in the end. Vasya's task is to stop his brother at some point and finish deleting himself in such a way, that the resulting word will be p. Since Petya likes this activity, Vasya wants to stop him as late as possible. Your task is to tell how many letters Petya can delete out before Vasya stops him.

    It is guaranteed that the word p can be obtained by deleting letters from t.
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

    ll t;
    cin >> t;

    while( t-- )
    {
        
    }
    return 0;
}