#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'K'. Find the 
 * length of the longest subarray with the sum of the elements 
 * equal to the given value 'K'.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int lengthOfLongestSubarrayWithSumK(vector<int>& nums, int n, int k) {
  unordered_map<int, int> map;
  int sum = 0, maxLength = 0;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
    if (sum == k) maxLength = i + 1;
    if (map.find(sum) == map.end()) map[sum] = i;
    if (map.find(sum - k) != map.end()) {
      if (maxLength < (i - map[sum - k])) {
        maxLength = i - map[sum - k];
      }
    }
  }
  return maxLength;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, num, k;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    cout << lengthOfLongestSubarrayWithSumK(nums, n, k) << '\n';
  }
  return 0;
}