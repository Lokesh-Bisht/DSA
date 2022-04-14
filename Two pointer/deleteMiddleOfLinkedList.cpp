#include <iostream>

using namespace std;

/**
 * Problem: Delete the middle element from a linked list. If the list 
 * is of even length then delete the second middle node.
 * 1 2 3 4 5 -> 1 2 4 5
 * 1 2 3 4 5 6 -> 1 2 3 5 6
 * Use Floyd's cycle finding algorithm (slow and fast pointer technique).
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

Node* deleteMiddle(Node* head) {
  if (head == NULL) {
    return NULL;
  }
  Node *slow = head;
  Node *fast = head;
  Node *prev = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
  }
  Node* temp = prev->next;
  prev->next = prev->next->next;
  delete(temp);
  return head;
}

void printList(Node* head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
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
    head = deleteMiddle(head);
    printList(head);
  }
  return 0;
}