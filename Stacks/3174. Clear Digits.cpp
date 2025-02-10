#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force) Inplace Solution
 * T.C : O(n^2)
 * - In the worst case, each digit removal causes a shift of O(n), leading to O(n^2) complexity
 * S.C : O(1)
 * - We modify the input string in place without extra space.
 * ----------------------------
 */
class Solution
{
public:
  string clearDigits(string s)
  {
    int i = 0; // Initialize index pointer

    // Iterate through the string
    while (i < s.size())
    {
      if (isdigit(s[i]))
      { // Check if the character is a digit

        s.erase(i, 1); // Remove the digit
        if (i > 0)
        {
          s.erase(i - 1, 1); // Remove the preceding character
          i--;               // Adjust index to avoid skipping characters
        }
      }
      else
      {
        i++; // Move to the next character
      }
    }
    return s; // Return the modified string
  }
};

/*
 * Approach-2 (Using Stack)
 * T.C: O(n)
 * - We iterate through the string once, processing each character in O(1) time.
 * - Pushing and popping from a stack is O(1), leading to an overall O(n) complexity
 * ----------------------------
 * S.C: O(n)
 * - In the worst case, all characters are stored in the stack, requiring O(n) space.
 */
class Solution
{
public:
  string clearDigits(string s)
  {
    stack<char> st; // Stack to store non-digit characters

    // Iterate through each character in the string
    for (char &ch : s)
    {
      if (ch >= 'a' && ch <= 'z')
      {              // If character is a lowercase letter
        st.push(ch); // Push it onto the stack
      }
      else if (!st.empty())
      {           // If character is a digit and stack is not empty
        st.pop(); // Remove the top character from the stack
      }
    }

    string res = ""; // String to store the final result
    while (!st.empty())
    {                  // Process the stack to construct the result string
      res += st.top(); // Append the top character to the result string
      st.pop();        // Remove the top character
    }

    // Reverse the string to maintain the original order
    reverse(res.begin(), res.end());

    // Return the final processed string
    return res;
  }
};

/*
 * Approach-3 (Using String as a Stack)
 * - We use a string (`res`) to dynamically store the result, treating it as a stack.
 * - We iterate through the given string:
 *   - If the character is a **digit**, we remove the **last inserted character** from `res` (simulating stack pop).
 *   - Otherwise, we **append** the character to `res`.
 * - This ensures that digits act as a trigger to remove the last inserted character.
 * ----------------------------
 * T.C : O(n)
 * - We process each character once in O(1) time, leading to an overall O(n) complexity.
 * ----------------------------
 * S.C : O(n)
 * - In the worst case, all non-digit characters are stored in `res`, leading to O(n) space usage.
 */
class Solution
{
public:
  string clearDigits(string s)
  {
    // Initialize an empty string to store the result
    string res = "";

    // Iterate through each character in the input string
    for (auto ch : s)
    {
      // If the character is a digit, remove the last inserted character
      if (isdigit(ch))
      {
        // Check if res is not empty
        if (!res.empty())
        {
          res.pop_back();
        }
      }
      // Otherwise, append the character to the result string
      else
      {
        res += ch;
      }
    }

    // Return the final processed string
    return res;
  }
};

/*
 * Approach-4 (In-place Modification)
 * - We use two pointers (`i` for traversal, `j` for writing valid characters).
 * - If the character is a **digit**, we remove the last added character by decrementing `j`.
 * - Otherwise, we copy the character to `s[j]` and increment `j`.
 * - Finally, we resize `s` to only keep valid characters.
 *
 * T.C : O(n)
 * - Each character is processed once, leading to an overall O(n) complexity.
 *
 * S.C : O(1)
 * - We modify the string in place without using extra space.
 * ----------------------------
 */
class Solution
{
public:
  string clearDigits(string s)
  {
    // Get the length of the input string
    int n = s.length();

    // Initialize two pointers: i for traversal, j for storing valid characters
    int i = 0, j = 0;

    // Iterate through each character in the string
    while (i < n)
    {
      // If the character is a digit, remove the last added character
      if (isdigit(s[i]))
      {
        j = max(j - 1, 0);
      }
      // Otherwise, store the character at index j
      else
      {
        s[j] = s[i];
        j++;
      }
      i++;
    }

    // Resize the string to only keep valid characters
    s.resize(j);

    // Return the final processed string
    return s;
  }
};