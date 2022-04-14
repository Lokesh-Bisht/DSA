#include <iostream>

using namespace std;

/**
 * Problem: Remove loop from a linked list.
 * Use Floyd's cycle finding algorithm (slow and fast pointer technique)
 * to find the loop in the cycle.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(1)
 */

struct Node {
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

void removeLoop(Node* head) {
  if (head == NULL) {
    return;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    // loop found
    if (slow == fast) {
      break;
    }
  }
  // for complete cycle (from the start to the end of the list)
  if (slow == head) {
    while (slow->next != fast) {
      slow = slow->next;
    }
    slow->next = NULL;
  } else if (slow == fast) {
    slow = head;
    while (slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, num;
    cin >> num;
    Node *head;
    Node *tail;
    head = tail = new Node(num);
    for (int i = 1; i < n; ++i) {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }
    removeLoop(head);
  }
  return 0;
}