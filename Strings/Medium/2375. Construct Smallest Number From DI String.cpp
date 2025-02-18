#include <bits/stdc++.h>
using namespace std;

// Approach - (Simple using string as a stack) - You can use a stack<int> as well
// T.C : O(n)
// S.C : O(n) for the result
class Solution
{
public:
  string smallestNumber(string pattern)
  {
    int n = pattern.length();

    string num = ""; //(n+1) //index 0 to index n

    int counter = 1;
    stack<char> st;

    for (int i = 0; i <= n; i++)
    {
      st.push(counter + '0');
      counter++;

      if (i == n || pattern[i] == 'I')
      {
        while (!st.empty())
        {
          num += st.top();
          st.pop();
        }
      }
    }

    return num;
  }
};
