#include <bits/stdc++.h>
using namespace std;

#include <string>

class Solution
{
public:
  int minLength(string s)
  {
    // Loop until no more "AB" or "CD" pairs can be found in the string
    while (s.find("AB") != -1 || s.find("CD") != -1)
    {
      // Check if "AB" is present in the string
      if (s.find("AB") != -1)
      {
        // Erase the first occurrence of "AB" from the string
        s.erase(s.find("AB"), 2); // Removes 2 char starting from the position of "AB"
      }
      // Check if "CD" is present in the string
      else if (s.find("CD") != -1)
      {
        // Erase the first occurrence of "CD" from the string
        s.erase(s.find("CD"), 2); // Removes 2 char starting from the position of "CD"
      }
    }

    // Return the length of the modified string after all pairs have been removed
    return s.length();
  }
};

// Approach-2 (Using stack)
// T.C : O(n)
// S.C : O(n)
#include <stack>
#include <string>

class Solution
{
public:
  int minLength(string s)
  {
    // Create a stack to keep track of characters
    stack<char> st;

    // Iterate through each character in the string
    for (int i = 0; i < s.length(); i++)
    {
      char currentChar = s[i]; // Get the current character

      // If the stack is empty, push the current character onto the stack
      if (st.empty())
      {
        st.push(currentChar);
        continue; // Move to the next character
      }

      // Check if the current character and the top of the stack form a removable pair "AB"
      if (currentChar == 'B' && st.top() == 'A')
      {
        // If they do, pop the top character from the stack
        st.pop(); // Removes 'A'
      }
      // Check if the current character and the top of the stack form a removable pair "CD"
      else if (currentChar == 'D' && st.top() == 'C')
      {
        // If they do, pop the top character from the stack
        st.pop();
      }
      else
      {
        // If no pair is found, push the current character onto the stack
        st.push(currentChar);
      }
    }

    // The size of the stack now represents the length of the modified string
    return st.size(); // Return the number of valid characters remaining
  }
};

// Approach-3 (Using 2 pointers = i : read, j ; write)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  int minLength(string s)
  {
    int i = 0;          // Write pointer
    int j = 1;          // Read pointer
    int n = s.length(); // Get the length of the input string

    // Iterate until 'j' reaches the end of the string
    while (j < n)
    {
      // Case when the write pointer 'i' is less than 0
      if (i < 0)
      {
        // Increment the write pointer 'i'
        i++;
        // Write the character from the read pointer 'j' to the write pointer 'i'
        s[i] = s[j];
      }
      // Check if the characters at the write pointer 'i' and read pointer 'j' form a pair to be removed: "AB" or "CD"
      else if ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D'))
      {
        // If a removable pair is found, decrement the write pointer 'i'
        // This effectively removes the pair from the resultant string
        i--;
      }
      else
      {
        // If no pair is found, increment 'i' to write the character from 'j'
        i++;
        // Write the character from the read pointer 'j' to the write pointer 'i'
        s[i] = s[j];
      }
      // Increment the read pointer 'j' to continue reading the next character
      j++;
    }
    // Return the new length of the modified string
    // 'i + 1' gives the number of valid characters written in the modified string
    return i + 1;
  }
};
