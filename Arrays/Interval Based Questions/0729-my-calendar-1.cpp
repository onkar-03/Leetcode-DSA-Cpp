#include <bits/stdc++.h> // Includes all standard C++ libraries for ease of use
using namespace std;     // Allows the use of standard library features without std:: prefix

// Approach-1 : Brute Force
// Time Complexity: O(n^2)
// The time complexity is quadratic due to the nested iterations over the bookings.
// For each booking, we iterate through all previous bookings to check for conflicts in the calendar array that we created.
// This results in a performance cost that grows quadratically with the number of bookings, as we must compare each booking against all others in the worst-case scenario.

// S.C : O(n)   // Space complexity is linear as we store bookings in a vector

// Define a type alias P for a pair of integers (start and end times)
typedef pair<int, int> P;

class MyCalendar
{
public:
  // Vector to store booked time slots as pairs of integers
  vector<P> calendar;

  // Constructor for MyCalendar
  MyCalendar()
  {
    // Constructor is empty, initializes the calendar vector as empty
  }

  // Method to book a new time slot from start to end
  bool book(int start, int end)
  {

    // Loop through each existing booking in the calendar
    // For first iteration this loop is skipped as 0 < 0 is false and the first booking is directly entered in teh calendar
    for (int i = 0; i < calendar.size(); i++)
    {
      // Get the i-th booking from the calendar
      // This creates a curr of type P and initialises the i-th value of calendar to it
      P curr = calendar[i];

      // Check if the new booking overlaps with the current booking
      // 1. End should not be greater thanStart of curr
      // 2. Start should not be less than end of curr
      // If either of these conditions is true, there's an overlap and the booking cannot be made
      if (!(end <= curr.first || start >= curr.second))
        return false; // If there's an overlap, return false (booking cannot be made)
    }

    // Inserting valid bookings in calendar
    // If no overlaps were found, add the new booking to the calendar
    calendar.push_back({start, end});
    // Return true indicating the booking was successful
    return true;
  }
};

// Approach - 2 (Using a set with lower_bound)
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class MyCalendar
{
public:
  // A set to store the booked events as pairs of (start, end) times
  set<pair<int, int>> st;

  // Constructor: Initializes the MyCalendar instance
  MyCalendar()
  {
    // No specific initialization required for the set
  }

  // Function to book an event from 'start' to 'end'
  bool book(int start, int end)
  {
    // Use lower_bound to find the first event that starts at or after the 'start' time
    // lower_bound(x) gives an element that is >= x
    // For pairs gives an element that is >= first element of the Pair
    // If it finds nothing then it points to the st.end() i.e. end of the set

    // First iteration st.end()
    // Second Iteration {10,20} and so on ...
    auto it = st.lower_bound({start, end}); // O(log n) and for n elements 0(n* log n)

    // Check if the current event overlaps with the next event
    // 'it' points to the first event that starts after 'start'
    // If it is not the end of the set and its start time is less than the 'end' time of the event to be booked, there's an overlap
    if (it != st.end() && it->first < end)
    {
      // Event cannot be booked due to overlap
      return false;
    }

    // Check if the current event overlaps with the previous event
    // 'it' points to the first event that starts after 'start'
    // If 'it' is not the beginning of the set means that the set is not empty, we check the previous event
    if (it != st.begin())
    {
      // Get the iterator for the previous event
      // prev(it) gives us the previous event of the set than the current one
      auto prevIt = prev(it);

      // If the 'start' time of the new event is less than the end
      // time of the previous event, there's an overlap
      if (start < prevIt->second)
      {
        return false; // Event cannot be booked due to overlap
      }
    }

    // If no overlaps were found, insert the new event into the set
    st.insert({start, end}); // Add the event to the calendar
    return true;             // Successfully booked the event
  }
};

/*
EG: Test Case
[ [10, 20], [15, 25], [20, 30]]
*/