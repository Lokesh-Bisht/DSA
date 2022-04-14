#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Detect loop in a linked list.
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

/**
 * Use unordered set to store the address of nodes. If you visit 
 * a node that's address is already present in the unordered set
 * then you have found the loop.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */
bool detectLoop(Node* head) {
  set<Node*> address;
  address.insert(head);
  while (head != NULL) {
    head = head->next;
    if (address.find(head) == address.end()) {
      address.insert(head);
    } else {
      return true;
    }
  }
  return false;
}

/**
 * Use Floyd's cycle finding algorithm (slow and fast pointer technique)
 * to detect loop in a cycle.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(1)
 */

bool detectLoop(Node* head) {
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) return true;
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, num;
    cin >> n;

    Node *head;
    Node *tail;
    cin >> num;
    head = tail = new Node(num);
    for (int i = 1; i < n; ++i) {
      cin >> num;
      tail->next = new Node(num);
      tail = tail->next;
    }

    if (detectLoop(head)) {
      cout << "The linked list contains a loop." << endl;
    } else {
      cout << "There is not loop in the linked list." << endl;
    }
  }
  return 0;
}