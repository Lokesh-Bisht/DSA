#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: Given an array of distinct integers. Count the number
 * of triplets such that sum of two elements equals the third
 * element.
 * 
 * TC: O(n2 + nlogn)
 * SC: O(n)
 * AC: O(1)
 */

int findTripletSum(vector<int>& nums, int n, int x) {
  sort(nums.begin(), nums.end());
  int count = 0;
  for (int i = 2; i < n; ++i) {
    int currentElement = nums[i];
    int l = 0, r = i - 1;
    while (l < r) {
      if (nums[i] == nums[l] + nums[r]) {
        count++, l++, r--;
      }
      else if (nums[i] > nums[l] + nums[r]) l++;
      else r--;
    }
  }
  return count;
}