#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    // Number of friends (based on the size of the input vector)
    int n = times.size();
    // Array to track when each chair will be free. -1 means the chair is available initially.
    vector<int> chairs(n, -1);

    // Get the arrival time of the target friend to track when they arrive
    int targetFriendArrivalTime = times[targetFriend][0];

    // Sort the 'times' array based on the arrival times of friends. This is necessary to allocate chairs in the order of arrival, so that we handle the earliest arrivals first.
    sort(times.begin(), times.end());

    // Loop over each friend's arrival and departure time
    for (vector<int> &time : times)
    {
      int arrival = time[0];   // Friend's arrival time
      int departure = time[1]; // Friend's departure time

      // Check every chair to see if it is free at the current friend's arrival time
      for (int i = 0; i < n; i++)
      {
        // If chair i is either available (chair[i] == -1) or will be free by the time of the friend's arrival (chairs[i] <= arrive, we assign this chair to the current friend.
        if (chairs[i] <= arrival)
        {
          chairs[i] = departure; // Mark the chair as occupied until the current friend's departure time.

          // If this friend is the target friend (i.e., the arrival time matches the target friend's arrival time), return the current chair index `i` because this is the chair assigned to the target friend.
          if (arrival == targetFriendArrivalTime)
          {
            return i; // Return the chair index for the target friend.
          }
          // After assigning the chair, exit the inner loop and move to the next friend in the outer loop.
          break;
        }
      }
    }
    // Never executed if we know target friend is always assigned a chair
    return -1;
  }
};
