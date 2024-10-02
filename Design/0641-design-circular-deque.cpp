#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Array)
// T.C : O(1) for most operations (insert, delete)
// S.C : O(k), where k is the size of the deque

// Formulae to update Indexes in circular data structures is:
// front = (front - 1 + K) % K; (K: Size of the DataStructure)
// back = (back + 1) % K; (K: Size of the DataStructure)

class MyCircularDeque
{
public:
  // Dynamic Array to hold deque elements and its size
  vector<int> deq;
  int K; // Maximum capacity of the deque

  // Variables to hold the front and rear pointers
  int front;
  int rear;

  // Variable to hold the current count of elements in the deque
  int currentCount;

  // Constructor to initialize the deque with size k
  MyCircularDeque(int k)
  {
    // Set the max capacity to k
    K = k;

    // Initialize the deque with size k, filled with 0s
    deq = vector<int>(K, 0);

    // Front pointer starts at 0 (index)
    front = 0;

    // Rear pointer starts at K-1 (index, circular logic)
    rear = K - 1;

    // Initially, the deque is empty, so the count is 0
    currentCount = 0;
  }

  // Function to insert an element at the front of the deque
  bool insertFront(int value)
  {
    // Check if deque is full, return false if full
    if (isFull())
    {
      return false;
    }

    // Update front index (circularly) before inserting
    front = (front - 1 + K) % K;

    // Insert the value at the new front index
    deq[front] = value;

    // Increase the count of elements
    currentCount++;

    // Return true as the operation was successful
    return true;
  }

  // Function to insert an element at the rear of the deque
  bool insertLast(int value)
  {
    // Check if deque is full, return false if full
    if (isFull())
    {
      return false;
    }

    // Update rear index (circularly) before inserting
    rear = (rear + 1) % K;

    // Insert the value at the new rear index
    deq[rear] = value;

    // Increase the count of elements
    currentCount++;

    // Return true as the operation was successful
    return true;
  }

  // Function to delete an element from the front of the deque
  bool deleteFront()
  {
    // Check if deque is empty, return false if empty
    if (isEmpty())
    {
      return false;
    }

    // Update front index (circularly) after deletion, no need to actually delete the element
    // The element will be replaced by a new element in future iterations
    front = (front + 1) % K;

    // Decrease the count of elements
    currentCount--;

    // Return true as the operation was successful
    return true;
  }

  // Function to delete an element from the rear of the deque
  bool deleteLast()
  {
    // Check if deque is empty, return false if empty
    if (isEmpty())
    {
      return false;
    }

    // Update rear index (circularly) after deletion, no need to actually delete the element
    // The element will be replaced by a new element in future iterations
    rear = (rear - 1 + K) % K;

    // Decrease the count of elements
    currentCount--;

    // Return true as the operation was successful
    return true;
  }

  // Function to get the front element of the deque
  int getFront()
  {
    // If deque is empty, return -1
    if (isEmpty())
    {
      return -1;
    }

    // Return the front element
    return deq[front];
  }

  // Function to get the rear element of the deque
  int getRear()
  {
    // If deque is empty, return -1
    if (isEmpty())
    {
      return -1;
    }

    // Return the rear element
    return deq[rear];
  }

  // Function to check if deque is empty
  bool isEmpty()
  {
    // Returns true if no elements are present
    return currentCount == 0;
  }

  // Function to check if deque is full
  bool isFull()
  {
    // Returns true if the deque is at maximum capacity
    return currentCount == K;
  }
};

// Approach-2 (Using Doubly Linked List)
// T.C : O(1) for most operations (insert, delete)
// S.C : O(k), where k is the size of the deque

class MyCircularDeque
{
private:
  // Using a doubly linked list to store elements
  list<int> deq;

  // Current number of elements in the deque
  int cnt;

  // Maximum capacity of the deque
  int k;

public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int k)
  {
    // Set the maximum capacity
    this->k = k;

    // Initialize the current element count to 0 (deque is empty initially)
    cnt = 0;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value)
  {
    // Check if deque is full
    if (cnt == k)
    {
      return false; // Insertion fails if deque is full
    }

    // Insert the value at the front of the deque
    deq.push_front(value);

    // Increment the count of elements
    ++cnt;

    // Insertion successful, return true
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value)
  {
    // Check if deque is full
    if (cnt == k)
    {
      return false; // Insertion fails if deque is full
    }

    // Insert the value at the rear of the deque
    deq.push_back(value);

    // Increment the count of elements
    ++cnt;

    // Insertion successful, return true
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront()
  {
    // Check if deque is empty
    if (cnt == 0)
    {
      return false; // Deletion fails if deque is empty
    }

    // Remove the element from the front of the deque
    deq.pop_front();

    // Decrease the count of elements
    --cnt;

    // Deletion successful, return true
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast()
  {
    // Check if deque is empty
    if (cnt == 0)
    {
      return false; // Deletion fails if deque is empty
    }

    // Remove the element from the rear of the deque
    deq.pop_back();

    // Decrease the count of elements
    --cnt;

    // Deletion successful, return true
    return true;
  }

  /** Get the front item from the deque. */
  int getFront()
  {
    // Check if deque is empty
    if (cnt == 0)
    {
      return -1; // Return -1 if deque is empty
    }

    // Return the element at the front of the deque
    return deq.front();
  }

  /** Get the last item from the deque. */
  int getRear()
  {
    // Check if deque is empty
    if (cnt == 0)
    {
      return -1; // Return -1 if deque is empty
    }

    // Return the element at the rear of the deque
    return deq.back();
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty()
  {
    // Return true if deque is empty (count is 0)
    return cnt == 0;
  }

  /** Checks whether the circular deque is full or not. */
  bool isFull()
  {
    // Return true if deque is full (count equals capacity)
    return cnt == k;
  }
};
