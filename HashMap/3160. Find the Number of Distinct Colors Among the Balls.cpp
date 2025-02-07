#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: (Using array and hashmap)
 * - We use an array (`ballArr`) to keep track of the color of each ball.
 * - A hashmap (`colormp`) stores the count of each color currently present.
 * - For each query, we update the color of a ball and adjust the color count in the hashmap.
 * - If a ball already has a color, we decrease its previous color count and remove it if it becomes zero.
 * - The number of distinct colors is stored in the result for each query.
 * --------------------
 * T.C: O(n)
 * - We process each query in O(1) time, leading to a total complexity of O(n).
 * --------------------
 * S.C: O(limit) - This will cause MLE
 * - The `ballArr` array stores `limit+1` elements.
 * - The `colormp` hashmap can store up to `limit` entries in the worst case.
 */
class Solution
{
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries)
  {
    // Get the number of queries
    int n = queries.size();

    // Stores the number of distinct colors after each query
    vector<int> result(n);

    // Maps color -> count of occurrences
    unordered_map<int, int> colormp;

    // Stores color of each ball, initialized to -1
    vector<int> ballArr(limit + 1, -1);

    // Process each query
    for (int i = 0; i < n; i++)
    {
      // Extract ball index and color from query
      int ball = queries[i][0];
      int color = queries[i][1];

      // If the ball already has a color assigned
      if (ballArr[ball] != -1)
      {
        // Get the previous color of the ball
        int prevColor = ballArr[ball];

        // Decrease the count of the previous color
        colormp[prevColor]--;

        // If no balls have this color anymore, remove it from the hashmap
        if (colormp[prevColor] == 0)
        {
          colormp.erase(prevColor);
        }
      }

      // Assign the new color to the ball
      ballArr[ball] = color;

      // Increase count of the new color in the hashmap
      colormp[color]++;

      // Store the number of distinct colors after this query
      result[i] = colormp.size();
    }

    // Return results of all queries
    return result;
  }
};

/*
 * Approach-2: (Using Two Hashmaps)
 * - We use `ballMp` to store the color assigned to each ball.
 * - We use `colorMp` to track the count of each color present in the system.
 * - For each query, if the ball already has a color, we decrement the count of the previous color.
 * - If a color's count becomes zero, we remove it from `colorMp` to maintain accurate distinct color count.
 * - Finally, we assign the new color to the ball and update the distinct color count in the result array.
 * --------------------
 * T.C: O(n)
 * - Each query is processed in O(1) time using hashmaps, leading to an overall complexity of O(n).
 * --------------------
 * S.C: O(n)
 * - In the worst case, we store `n` unique balls and colors in the hashmaps.
 */
class Solution
{
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries)
  {
    // Get the number of queries
    int n = queries.size();

    // Maps color -> count of occurrences
    unordered_map<int, int> colorMp;

    // Maps ball -> current color assigned
    unordered_map<int, int> ballMp;

    // Stores the number of distinct colors after each query
    vector<int> result(n);

    // Process each query
    for (int i = 0; i < n; i++)
    {
      // Extract ball index and color from query
      int ball = queries[i][0];
      int color = queries[i][1];

      // If the ball already has a color assigned
      if (ballMp.count(ball))
      {
        // Get the previous color of the ball
        int prevColor = ballMp[ball];

        // Decrease the count of the previous color
        colorMp[prevColor]--;

        // If no balls have this color anymore, remove it from the hashmap
        if (colorMp[prevColor] == 0)
        {
          colorMp.erase(prevColor);
        }
      }

      // Assign the new color to the ball
      ballMp[ball] = color;

      // Increase count of the new color in the hashmap
      colorMp[color]++;

      // Store the number of distinct colors after this query
      result[i] = colorMp.size();
    }

    // Return results of all queries
    return result;
  }
};