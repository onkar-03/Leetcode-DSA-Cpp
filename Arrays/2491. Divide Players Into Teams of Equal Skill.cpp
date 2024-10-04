#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using frequency of skills similar to counting sort)
// T.C : O(nlogn)
// S.C : O(1)
class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {
    int n = skill.size(); // Get the number of players

    // Sort the skills array in ascending order to easily pair the smallest with the largest skill
    sort(skill.begin(), skill.end());

    int i = 0;     // Start pointer (points to the lowest skill value)
    int j = n - 1; // End pointer (points to the highest skill value)

    // Calculate the sum of the first and last player's skill
    // We will check if this sum is consistent for all other pairs
    int s = skill[i] + skill[j];

    long long chem = 0; // Variable to store the total chemistry of all valid pairs

    // Iterate while the pointers have not crossed each other
    while (i < j)
    {
      // Current sum of the skills of players at positions i and j
      int currSkill = skill[i] + skill[j];

      // If the sum of skills for the current pair is not equal to the initial sum 's',then it's impossible to divide players into valid pairs, so return -1
      if (s != currSkill)
      {
        return -1;
      }

      // If sum of skills of players are equal then we calculate the chemistry
      // Add the chemistry for the current pair, which is the sum of their skills
      // We cast to long long to prevent overflow for large numbers
      chem += (long long)skill[i] + (long long)skill[j];

      // Move the start pointer to the right and the end pointer to the left for the next pair
      i++;
      j--;
    }
    // If we have successfully processed all pairs, return the total chemistry
    return chem;
  }
};
