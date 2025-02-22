/*

indian mythology srtory

temple of brahma ji
diamond rods
with disks placed on them
place the disks in ascending order only 
and pick one disk at a time only
you can tak ehelp from one heper disk
1 second = 1 movement
for 64 disks
2^64-1 seconds
585 billion years would be needed


brahma ji coding karte the
hamein bhi coiding karni chchiye

*/



#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

void printtowerofhanoi(int n, int& cnt, char src, char helper, char dest) {
    //base case if for 1 disk simply place it from src to destination
    if(n==1){
        cout<<src<<"->"<<dest<<endl;
        cnt++;
        return;
    }
    //lets do it for smaller inoput
    //we will place n-1 nodes from top from the src to helper with dest rod as helper
    printtowerofhanoi(n-1, cnt, src, dest, helper);
    cout<<src<<"->"<<dest<<endl;
    cnt++;
    //now we will place those n-1 nodes from helper to dest using src rod as helper
    printtowerofhanoi(n-1, cnt, helper, dest, src);
}


void solve(){
    int n;
    n = 20;
    int cnt = 0;
    printtowerofhanoi(n, cnt, 'S', 'H', 'D');
    cout<<cnt<<endl;
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

    