#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using frequency of skills similar to counting sort)
// T.C : O(nlogn) coz sorting
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

// Approach-2 (Using frequency of skills similar to counting sort)
// Time Complexity: O(n)
// Space Complexity: O(1000) ~= O(1) since skill values are bounded
class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {
    int n = skill.size(); // Get the number of players

    // Frequency array to count the occurrences of skill levels
    vector<int> vec(1001, 0); // Assuming skill values range from 0 to 1000
    int SUM = 0;              // Variable to hold the total sum of skills

    // Loop through the skill array to calculate the total sum
    // and update the frequency of each skill level
    for (int &s : skill)
    {
      SUM += s; // Update the total sum of skills
      vec[s]++; // Increment the frequency count for the current skill level
    }

    // Calculate the number of teams (each team has 2 players)
    int teams = n / 2;

    // If the total sum of skills is not divisible by the number of teams,
    // we cannot form pairs with the same combined skill
    if (SUM % teams != 0)
    {
      return -1; // Return -1 indicating pairing is not possible
    }

    // Target sum for each pair of players
    int target = SUM / teams;
    long long chem = 0; // Variable to hold the total git comchemistry of valid pairs

    // Loop through each skill value to calculate chemistry
    for (int i = 0; i < n; i++)
    {
      int currSkill = skill[i];             // Current player's skill
      int remainSkill = target - currSkill; // Required skill for a valid pair

      // If there are no remaining players with the required skill,
      // we cannot form a valid pair
      if (vec[remainSkill] <= 0)
      {
        return -1; // Return -1 indicating pairing is not possible
      }

      // Update chemistry based on the current player's skill and the required skill
      // Cast to long long to prevent overflow during multiplication
      chem += (long long)currSkill * (long long)(remainSkill);

      // Decrement the frequency of the required skill since it's now paired
      vec[remainSkill] -= 1;
    }

    // Divide by 2 because each pair has been counted twice (currSkill and remainSkill)
    return chem / 2;
  }
};
