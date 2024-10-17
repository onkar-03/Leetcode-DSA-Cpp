#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Define a type alias for a pair of an integer (frequency) and a character
  typedef pair<int, char> P;

  // Function to generate the longest diverse string
  string longestDiverseString(int a, int b, int c)
  {
    // Create a max-heap (priority queue) to store pairs of frequency and character
    priority_queue<P, vector<P>> pq;

    // Push 'a' into the heap if its count is greater than 0
    if (a > 0)
    {
      pq.push({a, 'a'});
    }
    // Push 'b' into the heap if its count is greater than 0
    if (b > 0)
    {
      pq.push({b, 'b'});
    }
    // Push 'c' into the heap if its count is greater than 0
    if (c > 0)
    {
      pq.push({c, 'c'});
    }

    // Initialize an empty string to store the result
    string result = "";

    // While there are characters left in the heap
    while (!pq.empty())
    {
      // Get the character with the highest remaining frequency
      int currCount = pq.top().first;
      int currChar = pq.top().second;
      pq.pop(); // Remove it from the heap

      // If the last two characters in the result are the same as the current one
      if (result.length() >= 2 && result[result.length() - 1] == currChar && result[result.length() - 2] == currChar)
      {
        // We can't use the current character due to repetition, so check the next most frequent character
        if (pq.empty())
        {
          // If no other characters are left, break the loop (no valid string can be formed)
          break;
        }

        // Get the next character with the second-highest frequency
        int nextCount = pq.top().first;
        int nextChar = pq.top().second;
        pq.pop(); // Remove it from the heap

        // Add this next character to the result
        result.push_back(nextChar);
        nextCount--; // Decrease the count for this character
        if (nextCount > 0)
        {
          // If this character still has remaining frequency, push it back into the heap
          pq.push({nextCount, nextChar});
        }

        // Push the original character back into the heap, as we skipped using it in this iteration
        pq.push({currCount, currChar});
      }
      else
      {
        // If it's safe to use the current character, add it to the result
        currCount--;                // Decrease its frequency
        result.push_back(currChar); // Append the character to the result
      }

      // If the current character still has remaining frequency, push it back into the heap
      if (currCount > 0)
      {
        pq.push({currCount, currChar});
      }
    }

    // Return the result string containing the longest diverse string
    return result;
  }
};
