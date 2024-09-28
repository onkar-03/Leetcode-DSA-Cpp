#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Array)
// T.C : O(1)
// S.C : O(k)
class MyCircularDeque
{
public:
  // Dynamic Array and its Sizes
  vector<int> deq;
  int K;

  // Variables to hold the front and rear pointers
  int front;
  int rear;

  // Variable to hold the current count of elements in the array
  int currentCount;

  MyCircularDeque(int k)
  {
    K = k;
    deq = vector<int>(K, 0);
    front = 0;
    rear = K - 1;
    currentCount = 0;
  }

  bool insertFront(int value)
  {
    if (isFull())
    {
      return false;
    }

    front = (front - 1 + K) % K;
    deq[front] = value;
    currentCount++;
    return true;
  }

  bool insertLast(int value)
  {
    if (isFull())
    {
      return false;
    }

    rear = (rear + 1) % K;
    deq[rear] = value;
    currentCount++;
    return true;
  }

  bool deleteFront()
  {
    if (isEmpty())
    {
      return false;
    }
    front = (front + 1) % K;
    currentCount--;
    return true;
  }

  bool deleteLast()
  {
    if (isEmpty())
    {
      return false;
    }

    rear = (rear - 1 + K) % K;
    currentCount--;
    return true;
  }

  int getFront()
  {
    if (isEmpty())
    {
      return -1;
    }

    return deq[front];
  }

  int getRear()
  {
    if (isEmpty())
    {
      return -1;
    }
    return deq[rear];
  }

  bool isEmpty()
  {
    return currentCount == 0;
  }

  bool isFull()
  {
    return currentCount == K;
  }
};