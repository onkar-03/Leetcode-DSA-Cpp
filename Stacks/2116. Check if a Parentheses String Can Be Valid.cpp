#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Stack)
// T.C: O(n) - We traverse the string once.
// S.C: O(n) - Space used by the stacks.
class Solution
{
public:
  bool canBeValid(string s, string locked)
  {
    int n = s.length();

    // If the length of the string is odd, it's impossible to make valid parentheses.
    if (n % 2 != 0)
    {
      return false;
    }

    stack<int> open;      // Stack to store indices of locked '('.
    stack<int> openClose; // Stack to store indices of unlocked characters ('0').

    // Traverse through the string.
    for (int i = 0; i < n; i++)
    {
      if (locked[i] == '0')
      {
        // If the character is unlocked ('0'), it can act as either '(' or ')'.
        openClose.push(i);
      }
      else if (s[i] == '(')
      {
        // If the character is a locked '(', push its index to the 'open' stack.
        open.push(i);
      }
      else if (s[i] == ')')
      {
        // If the character is a locked ')':
        if (!open.empty())
        {
          // If there's a '(' available in the 'open' stack, pair it and pop.
          open.pop();
        }
        else if (!openClose.empty())
        {
          // If no '(' is available, use an unlocked character as '(' and pop.
          openClose.pop();
        }
        else
        {
          // If no match is possible, the string cannot be valid.
          return false;
        }
      }
    }

    // Match any remaining '(' with available unlocked characters.
    while (!open.empty() && !openClose.empty() && open.top() < openClose.top())
    {
      open.pop();
      openClose.pop();
    }

    // If all '(' have been matched, return true, otherwise false.
    return open.empty();
  }
};
