/*
chat gpt solution 
they just inistialised the count of 
open and closed brackets with n and 
decrease their count by 1 in each frequient 
recursive call 

*/

#include "bits/stdc++.h"
#define int long long
using namespace std;

void print(int n, vector<string> &ans, string op, int open, int closed)
{
    if (open == 0 && closed == 0)  // Base case: valid sequence formed
    {
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;

    // Add an open bracket if available
    if (open > 0)
    {
        op1.push_back('(');
        print(n, ans, op1, open - 1, closed);
    }

    // Add a closed bracket if it maintains balance
    if (closed > open)
    {
        op2.push_back(')');
        print(n, ans, op2, open, closed - 1);
    }
}

void solve()
{
    int n = 4;
    vector<string> ans;
    string curr = "";
    print(n, ans, curr, n, n);
    
    for (auto &str : ans)
    {
        cout << str << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
