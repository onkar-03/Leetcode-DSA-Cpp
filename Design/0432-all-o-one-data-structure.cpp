#include <bits/stdc++.h>
using namespace std;

// Approach (Using unordered_map + doubly linked list)
// Time Complexity: O(1) for all operations (inc, dec, getMaxKey, getMinKey)
// Space Complexity: O(n) where n is the number of unique keys stored

class AllOne
{
private:
  // Doubly Linked List node to store frequency (count) and a set of keys with that count
  struct Node
  {
    int count;         // Frequency of the keys
    list<string> keys; // Keys with this frequency (unordered_set would be more optimal for removal)
    Node *prev, *next; // Pointers to the previous and next node in the doubly linked list

    Node(int c) : count(c), prev(nullptr), next(nullptr) {} // Constructor to initialize a node with given count
  };

  // Unordered map to store the mapping from a key to the node where its count/frequency is stored
  unordered_map<string, Node *> mp;

  // Pointers for the doubly linked list's head and tail nodes (for easy access to min and max frequencies)
  Node *head, *tail;

  // Helper function to add a new node with count `c` after the `prevNode` in the doubly linked list
  Node *addNodeAfter(Node *prevNode, int count)
  {
    Node *newNode = new Node(count); // Create a new node with the given count
    newNode->next = prevNode->next;  // Set new node's next to previous node's next
    newNode->prev = prevNode;        // Set new node's prev to prevNode

    // If prevNode has a next node, set its previous pointer to newNode
    if (prevNode->next)
    {
      prevNode->next->prev = newNode;
    }
    prevNode->next = newNode; // Set prevNode's next to newNode

    // If prevNode was the tail, update tail to be the new node
    if (tail == prevNode)
    {
      tail = newNode;
    }
    return newNode;
  }

  // Helper function to remove a node from the doubly linked list
  void removeNode(Node *node)
  {
    node->prev->next = node->next; // Connect the previous node to the next node
    if (node->next)
    {
      node->next->prev = node->prev; // Set the next node's previous pointer
    }
    // If the node was the tail, update the tail pointer
    if (tail == node)
    {
      tail = node->prev;
    }
    delete node; // Delete the node to free memory
  }

public:
  // Constructor to initialize the doubly linked list with a dummy head and tail
  AllOne()
  {
    head = new Node(0); // Dummy head node with count 0 (never stores any key)
    tail = head;        // Initially, tail is the same as head
  }

  // Function to increment the frequency of a key
  void inc(string key)
  {
    if (mp.find(key) == mp.end())
    {
      // Case 1: Key doesn't exist in the map, so we add it with frequency 1
      if (head->next == nullptr || head->next->count != 1)
      {
        // If there's no node with count 1, add a new one after the head
        addNodeAfter(head, 1);
      }
      head->next->keys.push_front(key); // Add the key to the node with count 1
      mp[key] = head->next;             // Update the map to point to this node
    }
    else
    {
      // Case 2: Key exists, so we need to move it to the node with the next higher frequency
      Node *curNode = mp[key];       // Get the current node where the key is stored
      int curCount = curNode->count; // Get its current frequency

      // Check if the next node exists and has count = curCount + 1
      if (curNode->next == nullptr || curNode->next->count != curCount + 1)
      {
        // If no node with count curCount + 1, create one
        addNodeAfter(curNode, curCount + 1);
      }
      curNode->next->keys.push_front(key); // Move the key to the new node
      mp[key] = curNode->next;             // Update the map to point to the new node

      // Remove the key from its current node
      curNode->keys.remove(key);
      if (curNode->keys.empty())
      {
        removeNode(curNode); // If the current node becomes empty, remove it
      }
    }
  }

  // Function to decrement the frequency of a key
  void dec(string key)
  {
    Node *curNode = mp[key];       // Get the current node where the key is stored
    int curCount = curNode->count; // Get its current frequency

    // Remove the key from the current node
    curNode->keys.remove(key);

    if (curCount == 1)
    {
      // If the frequency becomes zero, remove the key from the map
      mp.erase(key);
    }
    else
    {
      // Move the key to the node with the previous frequency
      if (curNode->prev == head || curNode->prev->count != curCount - 1)
      {
        // If no node with count curCount - 1, create one
        addNodeAfter(curNode->prev, curCount - 1);
      }
      curNode->prev->keys.push_front(key); // Move the key to the new node
      mp[key] = curNode->prev;             // Update the map to point to the new node
    }

    // If the current node becomes empty, remove it
    if (curNode->keys.empty())
    {
      removeNode(curNode);
    }
  }

  // Function to return the key with the maximum frequency
  string getMaxKey()
  {
    // If the tail node is the dummy head, there are no keys
    return (tail == head) ? "" : tail->keys.front();
  }

  // Function to return the key with the minimum frequency
  string getMinKey()
  {
    // If there's no node after the dummy head, there are no keys
    return (head->next == nullptr) ? "" : head->next->keys.front();
  }
};
