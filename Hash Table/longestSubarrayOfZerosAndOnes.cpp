#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Given an array of 0s and 1s. Find the length of the largest 
 * subarray with equal number of 0s and 1s.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int longestSubArray(vector<int>& nums, int n) {
  unordered_map<int, int> map;
  int ans = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i] == 0 ? -1 : 1;
    if (sum == 0) {
      ans = max(ans, i + 1);
    } else {
      if (map.find(sum) != map.end()) {
        ans = max(ans, i - map[sum]);
      } else {
        map[sum] = i;
      }
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
    cout << longestSubArray(nums, n) << '\n';
  }
}