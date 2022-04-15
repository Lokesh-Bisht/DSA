#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/**
 * Problem: Given an array having both positive and negative 
 * integers. The task is to compute the length of the largest 
 * subarray with sum 0.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int getLengthOfLongestSubarray(vector<int>& nums, int n) {
  int length = 0, sum = 0;
  unordered_map<int, int> hashTable;
  for (int i = 0; i < n; ++i) {
    sum += nums[i];
    if (sum == 0) {
      length = max(length, i + 1);
    } else if (hashTable.find(sum) != hashTable.end()) {
      length = max(length, i - hashTable[sum]);
    } else hashTable[sum] = i;
  }
  return length;
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
    cout << getLengthOfLongestSubarray(nums, n) << '\n';
  }
}