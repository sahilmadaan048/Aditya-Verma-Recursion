/*
aditya method

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

void print(string s, string curr, vector<string>& ans) {
    if(s.empty()){
        ans.push_back(curr);
        return;
    }

    //we will make two more string
    string op1 = curr;
    string op2 = curr;

    //for one of the string we will push the current chracter and a space while for the other one we weill add just the forst character
    op1.push_back(' ');
    op1.push_back(s[0]);
    op2.push_back(s[0]);
    s.erase(s.begin());

    print(s, op1, ans);
    print(s, op2, ans);
}


// void print(string s, string curr, vector<string>& ans) {
//     if (s.empty()) {
//         ans.push_back(curr);
//         return;
//     }

//     // Create two different paths for recursion
//     string op1 = curr + s[0] + " ";  // Add character and space
//     string op2 = curr + s[0];        // Add character without space

//     // Reduce the input string
//     s.erase(s.begin());

//     // Recurse with both options
//     print(s, op1, ans);
//     print(s, op2, ans);
// }

void solve(){
    string s = "ABC";
    int n = s.size();
    int idx = 0;
    vector<string> ans;
    string curr = "";
    curr.push_back(s[0]);
    s.erase(s.begin());
    print(s, curr, ans);
    for(auto &str: ans){
        cout<<str<<endl;
    }
    // cout<<ans[3].size();
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

    