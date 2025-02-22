/*
doing this problem using my method

by keeping track of the current index and the size of the input string

*/

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================



void print(string &ip, string &curr, vector<string> &res, int n, int idx) {
    // if (idx == n) { 
    //     res.push_back(curr);  // Store valid subset
    //     return;
    // }

    res.push_back(curr);
    for (int i = idx; i < n; i++) {
        // Ensure the string is sorted before using this condition
        if (i != idx && ip[i] == ip[i - 1]) continue;

        // Include character
        curr.push_back(ip[i]);
        print(ip, curr, res, n, i + 1);  // Move to next index
        curr.pop_back();  // Backtrack to restore state
    }

    // Also consider the empty subset by making a call without including anything
    if (idx == 0) res.push_back(curr);
}

void solve()
{
    string temp = "aab";
    string curr = "";
    sort(temp.begin(), temp.end()); // sort this string before passing into the recursove fucnction call that way we cam
    // figure out some way to skip the repeating characters by comparing with the index we are planning to track the indices oif the string
    vector<string> res;
    int n = temp.size();
    int idx = 0;
    print(temp, curr, res, n, idx);
    for (auto &str : res)
    {
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



// my method

// here we can pass by reference since we are not messing eith the original string
// void print(string &ip, string &curr, vector<string> &res, int n, int idx)
// {
//     // base case
//     // if we reach the end of the string siply store the curr string value into the res vectors
//     if (idx == n)
//     {
//         res.push_back(curr);
//         return;
//     }
//     // next we will have to make choices for all the indices of string ip from i-ind to size n to check they wanna be a part of our curr string or not
//     // and make recursive calls for the samw
//     int i = idx;
//     for (; i < n; i++)
//     {
//         // also check for sduolicates here
//         if (i != idx and ip[i] == ip[i - 1])       
//             continue; // we have already include these subsets into the res vectpr for i==ind case
//     }
//     // exclude the elemrtns and shift the index with 1 unit
//     print(ip, curr, res, n, idx + 1);
//     // include the current character of string into the current string

//     /*
//     we have to push_back here since curr+ip[i] will create a new string
//     */
//     i--;
//     curr.push_back(ip[i]);
//     print(ip, curr, res, n, idx + 1);
//     curr.pop_back();
// }
