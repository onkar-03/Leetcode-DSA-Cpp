#include <bits/stdc++.h>
using namespace std;

// Approach - BFS (asking for minimum moves - and problem different states)
// T.C : O(6!) : The puzzle has 6 ! = 720 possible permutations of the board, as there are 6 tiles, including the blank tile (0). In the worst case, BFS explores all permutations.
// S.C : O(6!) All states are stored in map
class Solution
{
public:
  int slidingPuzzle(vector<vector<int>> &board)
  {
    // Convert the initial 2x3 board into a single string representation
    string start = "";
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        start += to_string(board[i][j]);
      }
    }

    // Queue for BFS traversal, starting with the initial board state
    queue<string> que;
    que.push(start);

    // The target configuration for the board
    string target = "123450";

    // Method 1
    // Mapping of possible moves for each index of '0' in the string possible for a 2X3 Matrix
    unordered_map<int, vector<int>> mp;
    mp[0] = {1, 3};    // '0' at index 0 can swap with indices 1 and 3
    mp[1] = {0, 2, 4}; // '0' at index 1 can swap with indices 0, 2, and 4
    mp[2] = {1, 5};    // '0' at index 2 can swap with indices 1 and 5
    mp[3] = {0, 4};    // '0' at index 3 can swap with indices 0 and 4
    mp[4] = {1, 3, 5}; // '0' at index 4 can swap with indices 1, 3, and 5
    mp[5] = {2, 4};    // '0' at index 5 can swap with indices 2 and 4

    // Method 2
    // Another way to store all possible moves for each index of '0'
    // Directions for possible swaps based on '0' position as a Vector
    vector<vector<int>> mp = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    // Set to track visited states to avoid revisiting
    unordered_set<string> visited;
    visited.insert(start);

    // BFS level representing the number of moves
    int level = 0;

    // Perform BFS to find the shortest path to the target configuration
    while (!que.empty())
    {
      int n = que.size(); // Number of states to process at the current level

      while (n--)
      {
        // Get the current board state from the queue
        string curr = que.front();
        que.pop();

        // Check if the target configuration is reached
        if (curr == target)
        {
          return level;
        }

        // Find the index of '0' (empty space) in the current state
        int indexOfZero = curr.find('0');

        // Explore all possible moves for '0'
        for (int swapIdx : mp[indexOfZero])
        {
          // Create a new state by swapping '0' with a valid neighbor
          string newState = curr;
          swap(newState[indexOfZero], newState[swapIdx]);

          // If the new state hasn't been visited, add it to the queue
          if (visited.find(newState) == visited.end())
          {
            visited.insert(newState);
            que.push(newState);
          }
        }
      }

      // Increment the level after processing all states in the current level
      level++;
    }

    // If the target configuration cannot be reached, return -1
    return -1;
  }
};
