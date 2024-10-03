#include <bits/stdc++.h>
using namespace std;

// Approach-1: Simple and straightforward
// Time Complexity: O(n) for each booking operation, where n is the number of existing bookings
// Space Complexity: O(n) for storing overlapping regions and bookings
class MyCalendarTwo
{
public:
  // Vector of pairs to store regions that have double overlaps
  vector<pair<int, int>> doubleOverlappedRegion;
  // Vector of pairs to store all the bookings
  vector<pair<int, int>> overallBookings;

  // Constructor
  MyCalendarTwo()
  {
  }

  // Function to check if two time intervals overlap
  bool checkOverlap(int start1, int end1, int start2, int end2)
  {
    // Returns true if the intervals (start1, end1) and (start2, end2) overlap
    // Overlap condition: max(start1, start2) < min(end1, end2)
    return max(start1, start2) < min(end1, end2);
  }

  // Function to find the overlapping region between two intervals
  pair<int, int> findOverlappedRegion(int start1, int end1, int start2, int end2)
  {
    // Returns a pair representing the start and end of the overlapping region
    return {max(start1, start2), min(end1, end2)};
  }

  // Function to book a time interval [start, end]
  bool book(int start, int end)
  {
    // Case 1: Check for triple booking
    for (const pair<int, int> &region : doubleOverlappedRegion)
    {
      // If booking causes triple booking with existing double booking regions, return false
      if (checkOverlap(region.first, region.second, start, end))
      {
        return false; // Triple booking detected
      }
    }

    // Case 2: Check if the new booking causes a double booking
    for (const pair<int, int> &booking : overallBookings)
    {
      // If new booking overlaps with any existing booking
      if (checkOverlap(booking.first, booking.second, start, end))
      {
        // Record the overlapping region in doubleOverlappedRegion
        doubleOverlappedRegion.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
      }
    }

    // If no triple booking occurs, add the new booking to overallBookings
    overallBookings.push_back({start, end});
    return true; // Booking successful
  }
};