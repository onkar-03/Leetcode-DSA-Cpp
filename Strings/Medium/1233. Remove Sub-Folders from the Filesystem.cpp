#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using set and substring find)
// T.C : O(n*L^2)
// S.C : O(n) //You can consider the length of each character as well - O(n*L)
class Solution
{
public:
  // Function to remove subFolders from a given list of folder paths
  vector<string> removeSubfolders(vector<string> &folder)
  {
    // Initialize an unordered set with all folder paths for quick lookup
    unordered_set<string> st(begin(folder), end(folder));

    // Result vector to store non-subfolder paths
    vector<string> result;

    // Iterate through each folder in the folder list
    for (string &currFolder : folder)
    {
      // Boolean flag to check if the current folder is a subfolder
      bool isSubFolder = false;

      // Make a copy of the current folder path to add to the result if it's not a subfolder
      string tempFolder = currFolder;

      // Loop until we have checked all parent directories of the current folder
      while (!currFolder.empty())
      {
        // Find the position of the last '/' in the folder path
        size_t position = currFolder.find_last_of('/');

        // Update the current folder to its parent directory
        currFolder = currFolder.substr(0, position);

        // Check if the parent directory exists in the set
        if (st.find(currFolder) != st.end())
        {
          // If found, the current folder is a subfolder
          isSubFolder = true;
          break; // Exit the loop as we have confirmed it is a subfolder
        }
      }

      // If the folder is not a subfolder, add it to the result
      if (!isSubFolder)
      {
        result.push_back(tempFolder);
      }
    }

    // Return the result with only non-subfolder paths
    return result;
  }
};
