#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * - We continuously search for the substring `part` inside `s` and remove it.
 * - This process repeats until `part` is no longer found in `s`.
 * --------------------
 * T.C : O(m * n)
 * - Searching for `part` using `find()` takes O(n) in the worst case.
 * - Removing `part` using `erase()` also takes O(n) in the worst case.
 * - If this operation is repeated m times, the total complexity is O(m * n).
 * --------------------
 * S.C : O(1)
 * - We modify the input string `s` in place without using extra space.
 */
class Solution
{
public:
  string removeOccurrences(string s, string part)
  {
    // Run a loop until no occurrences of `part` are found in `s`
    while (true)
    {
      // Find the first occurrence of `part` in `s`
      int idx = s.find(part);

      // If `part` is not found, break out of the loop
      if (idx == string::npos)
      {
        break;
      }

      // Remove `part` from `s` at the found index
      s.erase(idx, part.length());
    }

    // Return the modified string after all removals
    return s;
  }
};

/*
 * Approach-2 (Using Stack)
 * - We use a stack to process characters one by one and check if the last `n` characters form `part`.
 * - If the last `n` characters match `part`, we remove them from the stack.
 * - Finally, we reconstruct the modified string from the stack.
 *
 * T.C : O(m * n)
 * - Each character is pushed onto the stack O(m) times.
 * - The check function runs in O(n) in the worst case.
 * - In total, the complexity is O(m * n).
 *
 * S.C : O(m)
 * - The stack can store at most `m` characters in the worst case.
 * --------------------
 */
class Solution
{
public:
  // Checks if the top `n` elements in the stack match `part`
  bool check(stack<char> &st, string &part, int n)
  {
    stack<char> tempSt = st;

    // Iterate through `part` from the last character to the first
    for (int idx = n - 1; idx >= 0; idx--)
    {
      // Return false if the top character doesn't match
      if (tempSt.top() != part[idx])
      {
        return false;
      }
      // Remove the top element from the temporary stack
      tempSt.pop();
    }
    return true;
  }

  string removeOccurrences(string s, string part)
  {
    // Stack to store characters while processing
    stack<char> st;

    // Length of the input string `s`
    int m = s.length();

    // Length of the substring `part`
    int n = part.length();

    // Traverse each character in the input string
    for (int i = 0; i < m; i++)
    {
      // Push the character onto the stack
      st.push(s[i]);

      // Check if the top `n` elements in the stack form `part`
      if (st.size() >= n && check(st, part, n) == true)
      {
        // Remove `n` elements from the stack if they match `part`
        for (int j = 0; j < n; j++)
        {
          st.pop();
        }
      }
    }

    // Initialize an empty result string
    string result = "";

    // Retrieve the remaining characters from the stack
    while (!st.empty())
    {
      // Append the top character to result
      result.push_back(st.top());

      // Remove the top element from the stack
      st.pop();
    }

    // Reverse the result string to correct order
    reverse(begin(result), end(result));

    // Return the final modified string
    return result;
  }
};

/*
 * Approach-3 (Using string as a stack)
 * - We use a string `result` as a stack to build the modified string.
 * - We iterate through `s`, adding each character to `result`.
 * - If the last `n` characters in `result` match `part`, we remove them.
 * - This mimics a stack-based approach but uses string operations.
 * --------------------
 * T.C : O(m * n)
 * - Each character is appended to `result`, which takes O(m).
 * - Checking for `part` using `substr()` takes O(n) in the worst case.
 * - In total, the complexity is O(m * n).
 * --------------------
 * S.C : O(1) (excluding result storage)
 * - We modify `result` in place without extra space.
 */
class Solution
{
public:
  string removeOccurrences(string s, string part)
  {
    // String used as a stack to build the modified result
    string result = "";

    // Length of the substring `part`
    int n = part.length();

    // Traverse each character in `s`
    for (char &ch : s)
    {
      // Add the current character to `result`
      result.push_back(ch);

      // Check if the last `n` characters in `result` match `part`
      if (result.length() >= n && result.substr(result.length() - n) == part)
      {
        // Remove the last `n` characters if they match `part`
        result.erase(result.length() - n);
      }
    }

    // Return the final modified string
    return result;
  }
};