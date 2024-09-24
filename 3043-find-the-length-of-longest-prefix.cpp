#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
  {
    // Set to store all possible prefixes of arr1
    unordered_set<int> s;

    // Loop through all numbers in arr1.
    for (auto val : arr1)
    {
      // For each number, repeatedly divide it by 10 (removing the last digit) until the number becomes 0 or a prefix that has already been added is found.
      while (!s.count(val) && val > 0)
      {
        s.insert(val); // Insert the current value or prefix into the set.
        val /= 10;     // Remove the last digit of the number to calculate the rest of the prefixes of the number until its > 0
      }
    }

    int result = 0; // Variable to store the length of the longest common prefix.

    // Loop through all numbers in arr2 to find common prefixes in the set.
    for (auto num : arr2)
    {
      // For each number, keep dividing it by 10 to find the common prefix in the set.
      while (!s.count(num) && num > 0)
      {
        num /= 10; // Remove the last digit to check if its prefix exists in the set.
      }

      // If a common prefix is found (num > 0), calculate its length.
      if (num > 0)
      {
        // Calculate the length of the common prefix by counting its digits.
        // Length of Number is calculated by log10(num) + 1 always
        result = max(result, static_cast<int>(log10(num)) + 1);
      }
    }

    return result; // Return the length of the longest common prefix.
  }
};

int main()
{
  Solution solution;

  int n1, n2;

  // Take input for arr1 and arr2 sizes
  cout << "Enter the number of elements in arr1: ";
  cin >> n1;
  vector<int> arr1(n1);

  cout << "Enter elements of arr1: ";
  for (int i = 0; i < n1; i++)
  {
    cin >> arr1[i];
  }

  cout << "Enter the number of elements in arr2: ";
  cin >> n2;
  vector<int> arr2(n2);

  cout << "Enter elements of arr2: ";
  for (int i = 0; i < n2; i++)
  {
    cin >> arr2[i];
  }

  // Call the function to get the longest common prefix length
  int ans = solution.longestCommonPrefix(arr1, arr2);

  cout << "Longest common prefix length: " << ans << endl;

  return 0;
}
