#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Global Var
  int m, n, l;

  // Valid Directions that we can move
  vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  // Function to find the characters of the word in the Board
  bool find(vector<vector<char>> &board, int i, int j, int index, string &word)
  {
    // Condition 1:
    // Index is used to keep track of the position of the current character in the word that we're trying to match on the board
    // All characters found !! means index is same as word length
    if (index == l)
    {
      return true; // All characters found
    }

    // Condition 2:
    // Base Conditions:
    // 1. Out of Bounds Check
    // 2. Already Visited Check
    // 3. Character does not match the character of the word
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[index])
    {
      return false; // Return false if any condition is met
    }

    // Mark Current Character as Visited: '$'
    char temp = board[i][j];
    board[i][j] = '$';

    // Search in all valid directions
    // On each iteration dir has one array as a value
    // On first iteration it has {1,0}, then {-1,0} and so on
    for (auto &dir : directions)
    {
      // As we want the 1 of {1,0} to be added to i we do i+=dir[0]
      // As we want the o of {1,0} to be added to j we do j+=dir[1]
      int new_i = i + dir[0];
      int new_j = j + dir[1];

      // Backtracking:
      // Check the next character
      // If not a valid match or path bound then we get false adn the if statements are not executed
      if (find(board, new_i, new_j, index + 1, word))
      {
        // If we find a match for the words, means we get index == length only then we return true
        return true;
      }
    }

    // Restore the character after backtracking:
    // After exploring a path (whether it leads to a match or not),we must restore the character at the current cell to its original value.
    // This is essential because we marked this cell as visited (with '$'), to avoid using it multiple times in the same path.
    // However, after the current path is explored, we need to reset the cell, so that it can be used again when exploring other potential paths from neighboring cells.
    // Backtracking ensures that the board remains unmodified after every exploration
    board[i][j] = temp;

    // If no match found in any direction, return false
    return false;
  }

  bool exist(vector<vector<char>> &board, string word)
  {
    // Calculate the Rows and Columns of 2D Vector
    m = board.size();
    n = board[0].size();

    // Calculate the length of the word
    l = word.length();

    // If the board's total cells are less than the word's length, return false
    if (m * n < l)
    {
      return false;
    }

    // Traverse all the cells of the Matrix
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // When we find the first matching character in the Matrix we
        // pass the string to find the rest of the characters of the string
        if (board[i][j] == word[0] && find(board, i, j, 0, word))
        {
          return true; // If the word exists, return true
        }
      }
    }

    // If no match then we return false
    return false;
  }
};
