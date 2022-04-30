#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given a sorted array containing only 0s and 1s, find the 
 * transition point. Return the index of the position where "0" ends 
 * and "1" begins. If array does not have any 1s, return -1. If array 
 * does not have any 0s, return 0.
 * 
 * nums = 0 0 0 1 1 
 * O/p: 3
 * 
 * nums = 0 0 0 
 * O/p: -1
 * 
 * nums = 1 1 1
 * O/p: 0
 *  
 * TC: O(log n)
 * SC: O(n)
 * AC: O(1)
 */


int transitionPoint(vector<int>& nums, int n) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (nums[mid] == 0) l = mid + 1;
    else r = mid - 1;
  }
  if (l == 0 && nums[l] == 1) return 0;
  if (l == n && nums[l - 1] == 0) return -1;
  return l;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, num;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    cout << transitionPoint(nums, n) << '\n';
  }
  return 0;
}