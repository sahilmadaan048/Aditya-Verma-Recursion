/*


same problem:

print subsets
print all subsets
print powersets
print all subsequences


powerset => set of all subsets
subsequences => contiguous may or may not be continuous but order matters ac is subsequemce 
substring => continuous for abc , ab and bc are substring but ac is not
subset => even order does not matter and they need not be continuous

in case of subset printing (a, b), or ( b, a) mean the same thing

substring , subsequences and subset difference is clear now


all variations =>

    print it in lexicographically order => sort the vector of string before printing
    for duplicates insert them inset it will remove all the suplicates
*/



/*
solving the problem for duplicates

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



unordered_set<string> st;
void print(string ip, string op) {
    if(ip.size() == 0) {
        st.insert(op);
        return;
    }
    string op1 = op;
    string op2 = op;

    //two choices are wither take the firs element of the incoming ip otr font take kt
    //dont include in op1
    //include in op2
    op2 += ip[0];
    ip.erase(ip.begin() + 0);

    print(ip, op1);
    print(ip, op2);
}

/*
if you wanna do it using pass by reference will have to backtrack
at the end of the recurtsion call
we will have to insert the deleted element back into the first position of the input string


kinda like this




*/




//---------------------------OTHER SOLUTIONS-------------------

unordered_set<string> st;  // To store unique subsequences

void print(string &ip, string op) {
    if (ip.empty()) {  // Base case: when input is empty, store the output
        st.insert(op);
        return;
    }

    string op1 = op;  
    string op2 = op;
    
    // Include the first character in op2
    op2.push_back(ip[0]);
    
    // Store first character before modifying ip
    char firstChar = ip[0];  
    ip.erase(ip.begin());  // Modify input by removing the first character

    // Recursive calls
    print(ip, op1);  // Exclude current character
    print(ip, op2);  // Include current character

    // Backtrack: Restore `ip` to its original state
    ip.insert(ip.begin(), firstChar);
}



//---------------------------OTHER SOLUTIONS-------------------



/*

we can do this without mantaining  a set
by simply sorting the input array before passing it into the recursove function call

see the other part o solution where i have used the other solution

*/

void solve(){
    string temp = "abc";
    string ans = "";
    print(temp, ans);
    vector<string> res(st.begin(), st.end());
    sort(res.begin(), res.end()); //if you want to print it lexicographically
    for(auto &str: res) {
        cout << str << endl;
    }
    cout << endl;
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

