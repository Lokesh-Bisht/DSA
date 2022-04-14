#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Problem: Find the number of pairs of elements in the array
 * whose sum is equal to 'k'.
 * 
 * TC: O(n)
 * SC: O(n)
 * AC: O(n)
 */

int getPairsCount(vector<int>& nums, int n, int k) {
  int count = 0;
  unordered_map<int, int> freq;
  for (int i = 0; i < n; ++i) freq[nums[i]]++;
  for (int i = 0; i < n; ++i) {
    count += freq[k - nums[i]];
    // remove pair (nums[i], nums[i])
    if (nums[i] == k - nums[i]) {
      count--;
    }
  }
  return count / 2;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, num;
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
      cin >> num;
      nums.push_back(num);
    }
    cout << getPairsCount(nums, n, k) << endl;
  }
}