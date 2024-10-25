#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using set and substring find)
// T.C : O(n*L^2)
// S.C : O(n)
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

// Approach-2 (Using Sorting)
// T.C : O(n * logn) Considering the length of each path, T.C : O(n * L * logn)
// S.C : O(1)  only a constant amount of additional space is used
class Solution
{
public:
  vector<string> removeSubfolders(vector<string> &folder)
  {
    // Step 1: Sort the folder paths lexicographically (alphabetically) to ensure that
    // each folder appears before its subfolders (e.g., "/a" appears before "/a/b").
    sort(begin(folder), end(folder));

    // Step 2: Initialize result with the first folder since it has no parent folders
    vector<string> result;
    result.push_back(folder[0]); // The first folder cannot be a sub-folder after sorting.

    // Step 3: Iterate over remaining folders and check if they are subfolders of the last added folder
    for (int i = 1; i < folder.size(); i++)
    {
      string currFolder = folder[i];
      string lastFolder = result.back();

      // Add a trailing '/' to lastFolder to check if currFolder starts with lastFolder + "/"
      lastFolder += '/';

      // Step 4: Check if currFolder is not a subfolder of lastFolder
      // If currFolder doesn't start with lastFolder, add it to the result
      // This condition checks if 'currFolder' does not start with 'lastFolder'
      // (meaning it is not a subfolder of 'lastFolder').

      // Explanation:
      // 'currFolder.find(lastFolder)' finds the starting position of 'lastFolder' within 'currFolder'.
      // If it returns 0, this means 'currFolder' starts with 'lastFolder', making it a subfolder.
      // For example, if lastFolder = "/a/" and currFolder = "/a/b", then currFolder.find(lastFolder) == 0.
      // Adding '/' at the end of lastFolder helps ensure exact matching with only immediate subfolders, so folders like "/abc" aren't mistaken as subfolders of "/a".
      // If 'currFolder' does not start with 'lastFolder' (find() != 0),
      // it indicates that 'currFolder' is not a subfolder, and it should be added to 'result'.
      if (currFolder.find(lastFolder) != 0)
      {
        result.push_back(currFolder);
      }
    }

    // Step 5: Return the result with non-subfolder paths only
    return result;
  }
};
