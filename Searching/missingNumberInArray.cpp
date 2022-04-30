#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: Given an array of size n-1 such that it only contains distinct 
 * integers in the range of 1 to n. Find the missing element.
 * 
 * nums = 1 2 3 5
 * O/p: 5
 *  
 * TC: O(n)
 * SC: O(n)
 * AC: O(1)
 */


int findMissingNumber(vector<int>& nums, int n) {
  int sum = 0;
  for (auto num : nums) {
    sum += num;
  }
  return (n * (n + 1) / 2 ) - sum;
}

// Another solution
int findMissingNumber(vector<int>& nums, int n) {
  for (int i = 0; i < n-1; ++i) {
    int correctPos = nums[i]-1;
      while (nums[i] >= 1 && nums[i] <= n-1 && nums[i] != nums[correctPos]) {
        swap(nums[i], nums[correctPos]);
        correctPos = nums[i]-1;
      }
  }
  for (int i = 0; i < n-1; ++i) if (nums[i] != i+1) return i+1;
  return n;
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
    cout << findMissingNumber(nums, n) << '\n';
  }
  return 0;
}