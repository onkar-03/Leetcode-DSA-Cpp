#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using simple conversion)
// T.C : O(n^2) - Iterating on each string and converting each character to integer
// S.C : O(n) - Using set
class Solution
{
public:
  string findDifferentBinaryString(vector<string> &nums)
  {
    unordered_set<int> st;

    for (string &num : nums)
    {
      st.insert(stoi(num, 0, 2));
    }

    int n = nums.size();

    string result = "";

    for (int number = 0; number <= 65536; number++)
    {
      if (st.find(number) == st.end())
      {
        result = bitset<16>(number).to_string();
        break;
      }
    }

    return result.substr(16 - n);
  }
};