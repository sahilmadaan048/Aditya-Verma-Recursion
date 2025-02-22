/*
sort a stack 

kinda like the sort a array problem 
we solved earleir

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

//function with the hypothesis to insert he valure val in the atack st to its rightful posiiiton using recursion
void insertSorted(stack<int>& st, int val) {
    if(st.empty() || st.top()<=val) { 
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    //indtucion step wjich asumes that the next recursiove call will insert ehe val to ithe atack in the right pisitooon
    insertSorted(st, val);
    st.push(top);
}

//recursive function with the hypithesis that it returns an sorted stack
void sort(stack<int>& st){
    if(st.size() == 1) {
        //sorted in itself
        return;
    }
    int top = st.top();
    st.pop();
    //induciton that it returns an sorted stack after removing the top most element 
    sort(st);
    //insertSorted funtion has the responsibility to tsake the top most element and push it belongs
    insertSorted(st, top);
}

void solve(){
    vi temp = {5, 4, 1,2, 3};
    stack<int> st;
    for(auto ele: temp) st.push(ele);
    sort(st);
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
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

    