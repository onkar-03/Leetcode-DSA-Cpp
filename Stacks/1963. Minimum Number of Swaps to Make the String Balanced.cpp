#include <bits/stdc++.h>
using namespace std;

// Approach: (without using stack)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  int minSwaps(string s)
  {
    int size = 0;

    for (char &ch : s)
    {
      if (ch == '[')
        size++;
      else if (size != 0)
        size--;
    }

    return (size + 1) / 2;
  }
};