#include <bits/stdc++.h>
using namespace std;

// Approach-1 Backtracking
// T.C : O(n!)
// S.C : O(n * n!), total possible sequences = n! and each having n length
class Solution
{
public:
  int n;

  void solve(string &tiles, vector<bool> &used, unordered_set<string> &result, string &curr)
  {
    result.insert(curr);

    for (int i = 0; i < n; i++)
    {
      if (used[i])
        continue;

      curr.push_back(tiles[i]);
      used[i] = true;

      solve(tiles, used, result, curr);

      used[i] = false;
      curr.pop_back();
    }
  }

  int numTilePossibilities(string tiles)
  {
    n = tiles.length();
    vector<bool> used(n, false);
    unordered_set<string> result;
    string curr = "";

    solve(tiles, used, result, curr);

    return result.size() - 1;
  }
};