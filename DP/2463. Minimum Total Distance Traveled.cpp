#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define MAX 10000000000000LL // Define a large constant to handle cases when repairs are impossible
  using ll = long long;      // Alias `ll` for `long long` for readability

  // Recursive function to find the minimum cost to repair all robots
  ll mincost(vector<int> &robot, int robo_pos, vector<int> &factories, int fact_pos, vector<vector<ll>> &mem)
  {
    if (robo_pos < 0)
      return 0; // Base case: all robots are repaired
    if (fact_pos < 0)
      return MAX; // Base case: robots are left, but no more factories available

    // Check memoized results to avoid recalculating
    if (mem[robo_pos][fact_pos] != -1)
      return mem[robo_pos][fact_pos];

    // Cost if we use the current factory to repair the current robot
    ll include = abs(robot[robo_pos] - factories[fact_pos]) + mincost(robot, robo_pos - 1, factories, fact_pos - 1, mem);

    // Cost if we skip the current factory for the current robot
    ll exclude = mincost(robot, robo_pos, factories, fact_pos - 1, mem);

    // Memoize and return the minimum cost of either including or excluding the factory
    return mem[robo_pos][fact_pos] = min(include, exclude);
  }

public:
  // Main function to calculate the minimum total repair cost
  long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
  {
    sort(robot.begin(), robot.end());     // Sort robots for optimal pairing
    sort(factory.begin(), factory.end()); // Sort factories by position

    // Convert multi-instance factories into a single list of positions
    vector<int> factories;
    for (int i = 0; i < factory.size(); ++i)
    {
      int pos = factory[i][0];        // Get the position of the factory
      int count = factory[i][1];      // Get the capacity of the factory
      for (int j = 0; j < count; ++j) // Add the position to the list for each available capacity
        factories.push_back(pos);
    }

    // Initialize memoization table with -1 to indicate un-computed states
    vector<vector<ll>> mem(robot.size(), vector<ll>(factories.size(), -1));

    // Calculate and return the minimum cost starting with all robots and all factories
    return mincost(robot, robot.size() - 1, factories, factories.size() - 1, mem);
  }
};
