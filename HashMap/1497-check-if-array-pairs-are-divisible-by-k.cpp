#include <bits/stdc++.h>
using namespace std;

// Approach-(simple remainder maths)
// T.C : O(n)
// S.C : O(k)
class Solution
{
public:
  // Function to determine if the array elements can be arranged into pairs such that the sum of each pair is divisible by k
  bool canArrange(vector<int> &arr, int k)
  {
    // Create a frequency vector to count occurrences of each remainder
    // mp[r] = x; Remainder r occurred x times
    vector<int> mp(k, 0);

    // Loop through each number in the input array
    for (int &num : arr)
    {
      // Calculate the remainder when num is divided by k
      // The formula(((num % k) + k) % k) ensures that the remainder is non-negative
      // This handles cases where num can be negative
      int rem = (((num % k) + k) % k); // Handling negative remainders
      mp[rem]++;                       // Increment the count for this particular remainder
    }

    // Check the count of numbers with remainder 0
    // Pairs of 0 can only be formed in even numbers
    if (mp[0] % 2 != 0) // If odd count of zeros
    {
      return false; // It's not possible to form pairs
    }

    // Loop through possible remainders from 1 to k/2
    for (int rem = 1; rem <= k / 2; rem++)
    {
      // Calculate the counterpart remainder that forms a valid pair
      int counterHalf = k - rem;
      // Check if the frequency of the current remainder matches
      // the frequency of its counterpart remainder
      // If they do not match, pairing is impossible
      if (mp[counterHalf] != mp[rem])
      {
        return false; // Return false if counts do not match
      }
    }

    // If all checks pass, the array can be arranged into valid pairs
    // Hence return true
    return true;
  }
};
