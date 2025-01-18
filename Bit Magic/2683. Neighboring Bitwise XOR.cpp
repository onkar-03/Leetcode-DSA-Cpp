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

// Approach-2: Simple observation of XOR property
// Time Complexity: O(n) - Single traversal of the array
// Space Complexity: O(1) - Constant space used
class Solution
{
public:
  bool doesValidArrayExist(vector<int> &derived)
  {
    // Initialize a variable to store the cumulative XOR of all elements
    int XOR = 0;

    // Traverse through the `derived` array and calculate the cumulative XOR
    for (int &x : derived)
    {
      XOR = XOR ^ x; // Update XOR by XORing it with the current element
    }

    // Key observation:
    // If the XOR of all elements in `derived` is 0, it means that the derived array is valid, and a possible original array exists. Return true if XOR is 0, otherwise return false
    return XOR == 0;
  }
};

// Approach-3: Count 1s to determine XOR result
// Time Complexity: O(n) - Single traversal of the array
// Space Complexity: O(1) - Constant space used
class Solution
{
public:
  bool doesValidArrayExist(vector<int> &derived)
  {
    // Initialize a variable to count the number of 1s in the array
    int count = 0;

    // Traverse through the `derived` array to count the number of 1s
    for (int &x : derived)
    {
      if (x == 1)
      {
        count++; // Increment count if the current element is 1
      }
    }

    // Key observation:
    // XOR of all elements in an array is equivalent to checking if the number of 1s in the array is even or odd:
    // - If the number of 1s is even, the XOR of all elements will be 0.
    // - If the number of 1s is odd, the XOR of all elements will be 1.
    // Therefore, a valid array exists if the count of 1s is even.
    return count % 2 == 0; // Return true if the count of 1s is even, false otherwise
  }
};

// original = {a, b, c, d, e}
// derived[] = {1, 0, 1, 0, 1}
// Explanation:
// - The `derived` array is constructed as follows:
//   derived[0] = a ^ b
//   derived[1] = b ^ c
//   derived[2] = c ^ d
//   derived[3] = d ^ e
//   derived[4] = e ^ a

// Observation:
// - If we take the XOR of all elements in the `derived` array:
//   derived[0] ^ derived[1] ^ derived[2] ^ derived[3] ^ derived[4]
//   = (a ^ b) ^ (b ^ c) ^ (c ^ d) ^ (d ^ e) ^ (e ^ a)
// - By the commutative and associative properties of XOR, the terms cancel out:
//   (a ^ a) ^ (b ^ b) ^ (c ^ c) ^ (d ^ d) ^ (e ^ e) = 0
// - Therefore, the XOR of all elements in `derived` will be `0` if the number of `1`s in the array is even.

// Key Insight:
// - Each `1` in `derived` corresponds to an XOR operation that resulted in `1`.
// - If the number of `1`s in `derived` is even, the XOR of all elements will be `0`.
// - If the number of `1`s is odd, the XOR of all elements will be `1`.

// Conclusion:
// - To determine if a valid original array exists, we simply count the number of `1`s in the `derived` array.
// - If the count is even, a valid original array exists (XOR == 0).
// - If the count is odd, no valid original array exists (XOR != 0).