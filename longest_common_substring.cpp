/**
 * 
 * 
    Problem Statement #
    Given a sequence, find the length of its Longest Palindromic Subsequence (LPS). In a palindromic subsequence, elements read the same backward and forward.

    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

    Example 1:

    Input: "abdbca"
    Output: 5
    Explanation: LPS is "abdba".
    Example 2:

    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "ddd".
    Example 3:

    Input: = "pqr"
    Output: 1
    Explanation: LPS could be "p", "q" or "r".
**/
#include <iostream>
#include <vector>
using namespace std;

int findLPSLengthRecursive(const string &st, int start , int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (!st.length())
        return 0;
    if (st[start] == st[end])
        return 2 + findLPSLengthRecursive(st, start + 1, end - 1);
    int skip_left = findLPSLengthRecursive(st, start + 1, end);
    int skip_right = findLPSLengthRecursive(st, start, end - 1);
    return max(skip_left, skip_right);
}

int findLPSLengthTopDown(vector<vector<int > >&dp, const string &st, int start , int end)
{
    // should pass in from outside, and clear it after used. 
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (dp[start][end] != -1) 
        return dp[start][end];
    if (st[start] == st[end])
        dp[start][end] = 2 + findLPSLengthTopDown(dp, st, start + 1, end - 1);
    else 
        dp[start][end] = max(findLPSLengthTopDown(dp, st, start + 1, end), findLPSLengthTopDown(dp, st, start, end - 1));
    return dp[start][end];
}

int findLPSLength(const string &st) {

    return findLPSLengthRecursive(st, 0, st.length() - 1);
    vector<vector<int> > dp(st.length(), vector<int>(st.length() + 1, -1)); 
    return findLPSLengthTopDown(dp, st, 0, st.length() - 1);
}

int main(int argc, char *argv[]) {
  cout << findLPSLength("abdbca") << endl; // -> 5
  cout << findLPSLength("cddpd") << endl;  // -> 3
  cout << findLPSLength("pqr") << endl;    // -> 1
}