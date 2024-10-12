#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// T.C : O(n^2)
// S.C : O(n)
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

// Approach-2 (Using min-heaps)
// T.C : O(nlogn)
// S.C : O(n)
class Solution
{
public:
  int smallestChair(vector<vector<int>> &times, int targetFriend)
  {
    // Number of friends (based on the size of the input vector)
    int n = times.size();

    // Priority queue to track occupied chairs: (departure time, chair number).
    // The priority queue will store pairs where the top element is the one with the earliest departure time, allowing us to free chairs as friends leave.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;

    // Priority queue to track free chairs: smallest chair number will be at the top (min-heap).
    // This queue helps us allocate the smallest available chair number when assigning chairs.
    priority_queue<int, vector<int>, greater<int>> free;

    // Get the arrival time of the target friend to track when they arrive
    int targetFriendArrivalTime = times[targetFriend][0];

    // Variable to assign chair numbers sequentially as new chairs are needed.
    int chairNumber = 0;

    // Sort the 'times' array based on arrival times so that we can allocate chairs in the correct order.
    sort(times.begin(), times.end());

    // Iterate through each friend's arrival and departure times
    for (int i = 0; i < n; i++)
    {
      int arrival = times[i][0];   // Friend's arrival time
      int departure = times[i][1]; // Friend's departure time

      // Free up any chairs where the friend has already departed by the current friend's arrival time.
      // We check the top of the 'occupied' queue, and if the top chair's departure time is earlier or equal to the current arrival, we push it back to the 'free' queue since it becomes available.
      while (!occupied.empty() && occupied.top().first <= arrival)
      {
        // Add the chair back to the available free queue
        free.push(occupied.top().second);
        // Remove it from the occupied queue
        occupied.pop();
      }

      // If no chairs are free, assign a new chair number.
      if (free.empty())
      {
        // No chairs available in 'free', so assign a new chair and increment chairNumber
        occupied.push({departure, chairNumber});

        // If this friend is the target friend, return the assigned chair number.
        if (arrival == targetFriendArrivalTime)
        {
          // Return the current chair number
          return chairNumber;
        }
        // Increment chair number
        chairNumber++;
      }
      else
      {

        // If there are free chairs, we allocate the smallest available chair.
        int leastChairAvailable = free.top();
        free.pop(); // Remove the chair from the available queue

        // If the current friend is the target friend, return the chair number they're assigned.
        if (arrival == targetFriendArrivalTime)
        {
          return leastChairAvailable;
        }

        // Assign the available chair to the current friend and mark it as occupied until their departure.
        occupied.push({departure, leastChairAvailable});
      }
    }

    return -1; // This line should never be reached if input guarantees a valid answer.
  }
};
