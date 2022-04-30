#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * Problem: An element is called a peak element if its value is not 
 * smaller than the value of its adjacent elements(if they exists). 
 * Given an array nums[] of size n, find the index of any one of its 
 * peak elements.
 * 
 * nums = 1 2 3 
 * O/p: 3
 *  
 * TC: O(log n)
 * SC: O(n)
 * AC: O(1)
 */


int findPeakElement(vector<int>& nums, int n) {
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if ((mid == 0 || nums[mid] >= nums[mid - 1]) && 
    (mid == n - 1 || nums[mid] >= nums[mid + 1])) {
      return mid;
    }
    if (mid > 0 && nums[mid] < nums[mid - 1]) r = mid - 1;
    else l = mid + 1;
  }
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
    cout << findPeakElement(nums, n) << '\n';
  }
  return 0;
}