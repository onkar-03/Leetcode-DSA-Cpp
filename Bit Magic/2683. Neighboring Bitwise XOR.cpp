#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Simulation, starting with 0 and starting with 1)
// T.C : O(n) + O(n) == O(N)
// S.C : O(n) because we make an arr of same size as derived
class Solution
{
public:
  bool doesValidArrayExist(vector<int> &derived)
  {
    // Get the size of the derived array.
    int n = derived.size();

    // Create an array to store the reconstructed values.
    vector<int> arr(n);

    // Case 1: Assume arr[0] = 0 and try to reconstruct the array.
    arr[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
      // Calculate the value of arr[i] using XOR property: arr[i] =
      // derived[i-1] ^ arr[i-1]
      arr[i + 1] = derived[i] ^ arr[i];
    }
    // Check if the derived property holds for the last pair (arr[n-1] ^
    // arr[0] == derived[n-1]).
    if ((arr[n - 1] ^ arr[0]) == derived[n - 1])
    {
      return true; // If valid, return true.
    }

    // Case 2: Assume arr[0] = 1 and try to reconstruct the array again.
    arr[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
      // Recalculate the value of arr[i] using the same logic.
      arr[i + 1] = derived[i] ^ arr[i];
    }
    // Check again if the derived property holds for the last pair.
    if ((arr[n - 1] ^ arr[0]) == derived[n - 1])
    {
      return true; // If valid, return true.
    }

    // If neither assumption (arr[0] = 0 or arr[0] = 1) works, return false.
    return false;
  }
};
