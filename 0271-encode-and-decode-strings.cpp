#include <bits/stdc++.h>
using namespace std;

/*
    Design algorithm to encode/decode: list of strings <-> string

    Encode/decode with non-ASCII delimiter: {len of str, "#", str}

    Time: O(n)
    Space: O(1)
*/

class Solution
{
public:
  // Encodes a list of strings to a single string.
  // Receives an array of Strings as Input
  string encode(vector<string> &strs)
  {
    string result = ""; // Initialize the result string to hold the encoded data

    // Iterate over each string in the input vector
    for (int i = 0; i < strs.size(); i++)
    {
      string str = strs[i]; // Get the current string
      // Append the length of the string, a delimiter '#', and the string itself to the result
      result += to_string(str.size()) + "#" + str;
    }

    return result; // Return the fully encoded string
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s)
  {
    vector<string> result; // Initialize a vector to hold the decoded strings

    int i = 0; // Initialize an index to traverse the encoded string
    // Continue until we have processed the entire encoded string
    while (i < s.size())
    {
      int j = i; // Start at the current index

      // Find the delimiter '#' to locate the end of the length of the string
      while (s[j] != '#')
      {
        j++; // Increment j until we find '#'
      }

      // Extract the length of the next string from the substring
      int length = stoi(s.substr(i, j - i));
      // Extract the actual string using the length we just parsed
      string str = s.substr(j + 1, length);
      // Add the decoded string to the result vector
      result.push_back(str);
      // Move the index 'i' past the processed length and string
      i = j + 1 + length;
    }

    return result; // Return the vector of decoded strings
  }

private:
};

int main()
{
  Solution solution;

  vector<string> Input = {"lint", "code", "love", "you"};
  string encode = solution.encode(Input); // Encode the input list of strings

  cout << "Encoded: ";
  cout << encode << endl; // Print the encoded string

  vector<string> decode = solution.decode(encode); // Decode the encoded string

  cout << "Decoded: " << endl;
  for (auto it : decode)
  {
    cout << it << " "; // Print each decoded string
  }

  return 0;
}
