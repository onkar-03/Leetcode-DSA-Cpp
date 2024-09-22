#include <bits/stdc++.h> // Includes all standard library headers (used in competitive programming)
using namespace std;     // Allows use of standard library functions without `std::` prefix

class Solution
{
public:
  // Method to convert a 1D array into a 2D array with dimensions m x n
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    // Check if the size of the original array is valid for conversion to a 2D array
    if (original.size() != m * n)
      return {}; // Return an empty 2D array if sizes don't match

    vector<vector<int>> res; // Initialize result 2D vector to store the final result

    // Iterate over each row to construct the 2D array
    for (int i = 0; i < m; i++)
    {
      int start = n * i;   // Starting index of the current row in the original array
      int end = start + n; // End index (exclusive) of the current row

      // Create a row by taking a slice from the original array and push it to the result
      res.push_back(vector<int>(original.begin() + start, original.begin() + end));
    }

    return res; // Return the constructed 2D array
  }
};

int main()
{
  Solution solution; // Create an object of the Solution class

  vector<int> arr = {1, 2, 3, 4}; // Define the original 1D array
  int m = 2;                      // Number of rows for the 2D array
  int n = 2;                      // Number of columns for the 2D array

  // Call the construct2DArray method with the original array and the dimensions
  vector<vector<int>> ans = solution.construct2DArray(arr, m, n);

  // Iterate through the resulting 2D array and print each element
  for (auto it : ans)
  {
    for (auto jt : it)
    {
      cout << jt << " "; // Print each element of the row
    }
    cout << endl; // Print newline after each row
  }

  return 0; // Indicate that the program executed successfully
}
