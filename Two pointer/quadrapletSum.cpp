#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of size 'n' and an integer 'x'. Check if 
 * the array contains a quadraplet that sums upto 'x'.
 * TC: O(n3 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

bool findTripletSum(vector<int>& nums, int n, int x) {
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n-3; ++i) {
    for (int j = i + 1; j < n-2; ++j) {
      int l = j + 1, r = n - 1;
      while (l < r) {
        if (nums[i] + nums[j] + nums[l] + nums[r] == x) return true;
        if (nums[i] + nums[j] + nums[l] + nums[r] > x) r--;
        else l++;
      }
    }
  }
  return false;
}