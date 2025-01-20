#include <bits/stdc++.h>
using namespace std;

// Approach - 1 (Brute Force)
// Time Complexity: O((m * n) * s * (m + n))
// - `s = arr.size()` which is equal to `m * n`.
// - For each element in `arr` (O(s)), we check if the corresponding row or column is completely painted by traversing its length (O(m + n) for each check).
// - This makes the total complexity O((m * n) * (m * n) * (m + n)).

// Space Complexity: O(m * n)
// - We use a matrix `mat` of size m * n to track the painted cells.

class Solution
{
public:
  // Helper function to check if an entire row in the matrix has been painted.
  // A row is considered painted if all its values are <= 0.
  bool checkRowPainted(vector<vector<int>> &mat, int row)
  {
    for (int col = 0; col < mat[0].size(); col++)
    { // Iterate over all columns in the row.
      if (mat[row][col] > 0)
      { // If any value in the row is not painted, return false.
        return false;
      }
    }
    return true; // All values in the row are painted.
  }

  // Helper function to check if an entire column in the matrix has been painted.
  // A column is considered painted if all its values are <= 0.
  bool checkColumnPainted(vector<vector<int>> &mat, int col)
  {
    for (int row = 0; row < mat.size(); row++)
    { // Iterate over all rows in the column.
      if (mat[row][col] > 0)
      { // If any value in the column is not painted, return false.
        return false;
      }
    }
    return true; // All values in the column are painted.
  }

  // Function to find the first index in the array `arr` after which either a full row
  // or a full column in the matrix `mat` is completely painted.
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
  {
    int m = mat.size();    // Number of rows in the matrix.
    int n = mat[0].size(); // Number of columns in the matrix.

    // Create a mapping from matrix values to their positions (row, column).
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < m; i++)
    { // Traverse through the rows of the matrix.
      for (int j = 0; j < n; j++)
      { // Traverse through the columns of the matrix.
        int val = mat[i][j];
        mp[val] = {i, j}; // Store the position of the value in the matrix.
      }
    }

    // Iterate through the array `arr` and mark cells in the matrix as painted.
    for (int i = 0; i < arr.size(); i++)
    {
      int val = arr[i];

      // Retrieve the row and column of the current value
      // auto [row, col] = mp[val];

      // Explicitly declare the type as pair<int, int>
      pair<int, int> cell = mp[val];
      int row = cell.first;
      int col = cell.second;

      // Mark the cell as painted.
      mat[row][col] = -1;

      // Check if either the entire row or column is painted after this step.
      if (checkRowPainted(mat, row) || checkColumnPainted(mat, col))
      {
        return i; // Return the current index if a row or column is completely painted.
      }
    }

    return -1; // Return -1 if no row or column is completely painted after processing all elements.
  }
};

// Approach - 2 (Better Approach)
// Time Complexity: O(m * n)
// - We iterate through all the elements of the matrix exactly once to track their positions (O(m * n)).
// - We also iterate through all the elements of `arr` (size `m * n`) and update row/column painted counts (O(m * n)).
// - Since both loops are independent, the overall time complexity remains O(m * n).

// Space Complexity: O((m * n) + m + n)
// - We use an unordered_map to store the positions of matrix elements, which requires O(m * n) space.
// - We also use two additional vectors to track the count of painted cells for each row (O(m)) and each column (O(n)).
class Solution
{
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
  {
    int m = mat.size();    // Number of rows in the matrix.
    int n = mat[0].size(); // Number of columns in the matrix.

    // Create a mapping from matrix values to their positions (row, column).
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int val = mat[i][j];
        mp[val] = {i, j}; // Store the position of each value.
      }
    }

    // Arrays to count how many cells in each row and column are painted.
    vector<int> rowPaintedCount(m, 0);
    vector<int> columnPaintedCount(n, 0);

    // Process the values in the order given by `arr`.
    for (int i = 0; i < arr.size(); i++)
    {
      int val = arr[i];

      // Get the row and column of the current value.
      // auto [row, col] = mp[val];

      // Explicitly declare the type as pair<int, int>
      pair<int, int> cell = mp[val];
      int row = cell.first;
      int col = cell.second;

      // Increment the counts for the corresponding row and column.
      rowPaintedCount[row]++;
      columnPaintedCount[col]++;

      // Check if the current row or column is completely painted.
      if (rowPaintedCount[row] == n || columnPaintedCount[col] == m)
      {
        return i; // Return the index where a row or column gets fully painted.
      }
    }

    return -1; // Return -1 if no row or column gets completely painted.
  }
};