/*
correction =>



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


// void print(int n, string curr, vector<string>& ans, int one, int zero){
//     if(curr.size() == n) {
//         ans.push_back(curr);
//         return;
//     }

//     string op1;
//     string op2;

//     if(one<n/2+1){
//         op1.push_back('1');
//         print(n, op1, ans, one+1, zero);
//     }
//     if(zero<n/2) {
//         op2.push_back('0');
//         print(n, op2, ans, one, zero+1);
//     }
// }



// void print(int n, string curr, vector<string>& ans, int one, int zero) {
//     if (curr.length() == n) {
//         ans.push_back(curr);
//         return;
//     }

//     if (one < n / 2+1) {
//         print(n, curr + "1", ans, one + 1, zero);
//     }
    
//     if (zero < n / 2) {
//         print(n, curr + "0", ans, one, zero + 1);
//     }
// }


/*
code to print all buinary strings f length n
*/


void print(int n, string curr, vector<string>& ans, int one, int zero) {
    if (curr.length() == n) {
        if(one>=zero){
            ans.push_back(curr);
        }
        return;
    }
    //always add 1a one
    print(n, curr+"1", ans, one+1, zero);
    
    //add zero onelu oif one>zero
    if(one>=zero){
        print(n, curr+"0", ans, one, zero+1);
    }
}


void generate(int n, string curr, int ones, int zeros, vector<string>& result) {
    if (curr.length() == n) {
        if (ones >= zeros) {  // Ensure total 1s are >= total 0s
            result.push_back(curr);
        }
        return;
    }

    // Always add '1'
    generate(n, curr + "1", ones + 1, zeros, result);

    // Add '0' only if ones >= zeros
    // if (ones >= zeros) {
        generate(n, curr + "0", ones, zeros + 1, result);
    // }
}

void solve() {
    int n = 4; // Change as needed
    vector<string> ans;
    // generate(n, "", 0, 0, ans);
    print(n, "", ans, 0, 0);

    for (const auto& str : ans) {
        cout << str << endl;
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

    

