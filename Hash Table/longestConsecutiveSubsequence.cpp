#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the length of the longest sub-sequence such that 
 * elements in the subsequence are consecutive integers, the 
 * consecutive numbers can be in any order.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int findLongestConsecutiveSubsequence(vector<int>& nums, int n) {
  int ans = 0;
  unordered_set<int> keys;
  for (int i = 0; i < n; ++i) {
    keys.insert(nums[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (keys.find(nums[i]-1) == keys.end()) {
      int j = nums[i];
      while (keys.find(j) != keys.end()) {
        ++j;
      }
      ans = max(ans, j - nums[i]);
    }
  }
  return ans;
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
    cout << findLongestConsecutiveSubsequence(nums, n) << '\n';
  }
}