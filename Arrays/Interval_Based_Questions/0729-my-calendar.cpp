#include <bits/stdc++.h> // Includes all standard C++ libraries for ease of use
using namespace std;     // Allows the use of standard library features without std:: prefix

// Approach-1 : Brute Force
// T.C : O(n^2) // Time complexity is quadratic due to nested iterations over bookings
// S.C : O(n)   // Space complexity is linear as we store bookings in a vector
typedef pair<int, int> P; // Define a type alias P for a pair of integers (start and end times)

class MyCalendar // Define the MyCalendar class
{
public:
  vector<P> calendar; // Vector to store booked time slots as pairs of integers

  MyCalendar() // Constructor for MyCalendar
  {
    // Constructor is empty, initializes the calendar vector as empty
  }

  // Method to book a new time slot from start to end
  bool book(int start, int end)
  {
    // Loop through each existing booking in the calendar
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

    // If no overlaps were found, add the new booking to the calendar
    calendar.push_back({start, end});
    return true; // Return true indicating the booking was successful
  }
};
